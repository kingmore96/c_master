制表符：\t 在不同的编辑器中显示宽度不一样。

用空格+个数，就可以保证显示宽度，在不同的编辑器中一致。



vim：

如果就用tab，设置 noexpandtab（不替换\t为空格） + tabstop=8（默认设置）+softtabstop=0（按tab就是制表符，而不是别的东西）

如果不用tab，设置 expandtab（替换\t为空格）+ tabstop=X（随便设置，4或者8）+ softtabstop=0（按tab就是制表符，不是其他东西）

softtabstop，用于tab和空格混用的项目，不研究它，等需要了再研究。

shiftwidth 自动缩进（>> << 和 enter键换行之后的缩进）



为啥c语言文件没enter后自动缩进？

set expandtab tabstop=8 shiftwidth=8 softtabstop=0 filetype=c **cindent autoindent**

为啥两个都需要？

- **`autoindent`**：缩进的“保底”机制，确保在没有复杂语法结构时，新行缩进与上一行一致。

- **`cindent`**：C 语言的“增强”机制，实现语法感知的智能缩进。

- **同时设置**：二者协同工作，`cindent` 在需要时覆盖 `autoindent` 的机械行为，提供更专业的缩进体验。






