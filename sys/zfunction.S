	.text
.globl zfunction
zfunction:
	mov    0x4(%esp),%eax
	and    $0xfffc01ff,%eax
	sar    $0x8,%eax
	or     $0xff000000,%eax
    ret