assume cs:code
code segment
        mov ax,0b800h
        mov ds,ax
        mov bx,07b8h
        mov cx,16
        mov ax,0441h
        s:mov [bx],ax
        inc bx
        inc bx
        loop s

        mov ax,4c00h
        int 21h
code ends
end

