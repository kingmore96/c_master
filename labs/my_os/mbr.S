;mbr
;--------------------------------------------------------------
SECTION MBR vstart=0x7c00
	mov ax,cs
	mov ds,ax
	mov es,ax
	mov ss,ax
	mov fs,ax
	mov sp,0x7c00 

;Using the 0x06 function to clear the screen, the screen clearing mechanism: simply scroll up all lines to clear the screen
;-------------------------------------------------------------------------
;INT 0x10	function number:0x06	fuction description: row up window
;-------------------------------------------------------------------------
;
;input:
;AH fuction number = 0x06
;AL = the number of lines that need to be rolled up (0 means that the selected target area needs to be completely cleared)
;BH = display properties of blank lines after roll up
;	| BG highlight control | Background View（R G B） | Front view highlight control | Front view（R G B） |
;	|----------------------| -------------------------| -----------------------------| --------------------|
;	|   Bit 7              | Bits 6-4     	          |   Bit 3                      |   Bits 2-0          |
;	black is 0x00
;	white is 0x07
;
;The standard text mode is 25 lines (0 to 24), with column numbers ranging from 0 to 79.
;CH = the row number of the top left corner of the target area.
;CL = the column number of the top left corner of the target area.
;DH = the row number of the bottom right corner of the target area.
;DL = the column number of the bottom right corner of the target area.
;if we need to clear the screen, we need to set the CH = 0x00,CL = 0x00,DH = 0x18(decimal system is 24),DL = 0x4f(decimal system is 79)
;
;output: 
;no return value

	mov ax,0x0600
	mov bx,0x0700
	mov cx,0x0000
	mov dx,0x184f

	int 0x10

;end of 0x06 function


;Using the 0x03 function to get the cursor position.
;---------------------------------------------------------------------------------------------------------------------------
;INT 0x10 	function number:0x03	function description: get cursor postion
;-------------------------------------------------------------------------------
;
;input:
;AH function number = 0x03
;BH = page number where the cursor in, 0 is the right page number that need to write.
;
;output:
;CH = cursor starting scanning line
;CL = cursor ending scanning line
;	Scan Line: 
;	In CRT displays, each character is composed of horizontal scan lines. 
;	CH and CL respectively represent the starting and ending scan lines in the vertical direction of the cursor,
;	 which together determine the display height of the cursor.
;DH = line number where the cursor is located
;DL = column number where the cursor is located

	mov ah,3
	mov bh,0

	int 0x10

;end of 0x03 function


;Using the 0x13 function to print the String.
;-----------------------------------------------------------------------------------------------
;INT 0x10	function number:0x13	function description: print the String.
;-----------------------------------------------------------------------------------------------
;
;input:
;AH = function number 0x13
;AL = how we write the String
;	0x00:String contains only characte, cursor position is not updated after display, attribute value is in BL  
;	0x01:String contains only characte, cursor position is updated after display, attribute value is in BL.  
;       0x02:String contains character and attribute value, cursor position is not updated after display.  
;       0x03:String contains character and attribute value, cursor position is updated after display.  
;	for example:
;		0x00 and 0x01 : we need to set the BL,the attribute value will be used in all the characters.
;			mov bl, 0x1f
;			str db "Hello"
;		0x02 and 0x03 : we need to specify the attribute value for each character.
;			colored_str db 'H', 0x1F, 'e', 0x1F, 'l', 0x1F, 'l', 0x1F, 'o', 0x1F
;BH = page number always 0
;BL = attribute value of character
;CX = length of String
;DH DL : row and column values of the starting position are displayed on the screen.
;ES BP : String's segment address and offset address.
;
;output:
;	print the String on the screen.
;

	mov ax,message
	mov bp,ax

	mov cx,5
	mov ax,0x1301
	mov bx,0x0002

	int 0x10

;end of the 0x13 function

	jmp $ 			;dead cycle

	message db "1 MSR"
	times 510-($-$$) db 0 	;fill the remaining space with zeros
	db 0x55,0xaa		;magic number which tells the BIOS it is a MSR.




