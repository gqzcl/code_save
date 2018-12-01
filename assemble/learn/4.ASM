assume cs:code
code segment
        mov ax,00000h
        mov ds,ax
        mov bx,0200h
        mov ax,0000h
        mov cx,64
        s:mov [bx],ax
        inc ax
        inc bx
        loop s

        mov ax,4c00h
        int 21h
code ends
end
