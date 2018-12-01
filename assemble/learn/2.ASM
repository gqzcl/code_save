assume cs:code
code segment
        mov ax,0b800h
        mov ds,ax

        mov bx,0
        mov [bx],0333h

        add bx,2
        mov [bx],0336h

        mov ax,4c00h
        int 21h
code ends
end
