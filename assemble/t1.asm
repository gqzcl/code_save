assume cs:code
code segment
	mov ah,2
	mov d1,3
	add d1,30h
	int 21h

	mov ah,2
	mov d1,6
	add d1,30h
	int 21h

	mov ah,4c00h
	int 21h
code ends
end
