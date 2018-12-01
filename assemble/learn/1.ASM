assume cs:code
code segment
        mov ah,2
        mov dl,6
        add dl,30h
        int 21h

        mov ah,2
        mov dl,9
        add dl,30h
        int 21h

        mov ah,4ch
        int 21h
code ends
end
