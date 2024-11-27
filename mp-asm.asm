
section .text
global calculate_dx_asm
global calculate_dy_asm
global calculate_z_asm
; Function to calculate dx = x2 - x1
calculate_dx_asm:
    mov rsi, rcx ; rsi = x1
    mov rdi, rdx ; rdi = x2
    mov r10, r8 ; r10 = dx
    mov rcx, r9 ; rcx = n (counter)
    test rcx, rcx ; Check if n == 0
    je calculate_dx_done ; Exit if no elements
calculate_dx_loop:
    movss xmm0, [rsi] ; Load x1[i] into xmm0
    movss xmm1, [rdi] ; Load x2[i] into xmm1
    subss xmm1, xmm0 ; xmm1 = x2[i] - x1[i]
    movss [r10], xmm1 ; Store result in dx[i]
    add rsi, 4 ; Increment x1 pointer
    add rdi, 4 ; Increment x2 pointer
    add r10, 4 ; Increment dx pointer
    dec rcx ; Decrement counter
    jnz calculate_dx_loop ; Loop if not zero
calculate_dx_done:
    ret
; Function to calculate dy = y2 - y1
calculate_dy_asm:
    mov rsi, rcx ; rsi = y1
    mov rdi, rdx ; rdi = y2
    mov r10, r8 ; r10 = dy
    mov rcx, r9 ; rcx = n (counter)
    test rcx, rcx ; Check if n == 0
    je calculate_dy_done ; Exit if no elements
calculate_dy_loop:
    movss xmm0, [rsi] ; Load y1[i] into xmm0
    movss xmm1, [rdi] ; Load y2[i] into xmm1
    subss xmm1, xmm0 ; xmm1 = y2[i] - y1[i]
    movss [r10], xmm1 ; Store result in dy[i]
    add rsi, 4 ; Increment y1 pointer
    add rdi, 4 ; Increment y2 pointer
    add r10, 4 ; Increment dy pointer
    dec rcx ; Decrement counter
    jnz calculate_dy_loop ; Loop if not zero
calculate_dy_done:
    ret
; Function to calculate z = sqrt(dx^2 + dy^2)
calculate_z_asm:
    mov rsi, rcx ; rsi = dx
    mov rdi, rdx ; rdi = dy
    mov r10, r8 ; r10 = z
    mov rcx, r9 ; rcx = n (counter)
    test rcx, rcx ; Check if n == 0
    je calculate_z_done ; Exit if no elements
calculate_z_loop:
    movss xmm0, [rsi] ; Load dx[i] into xmm0
    movss xmm1, [rdi] ; Load dy[i] into xmm1
    mulss xmm0, xmm0 ; xmm0 = dx[i]^2
    mulss xmm1, xmm1 ; xmm1 = dy[i]^2
    addss xmm0, xmm1 ; xmm0 = dx^2 + dy^2
    sqrtss xmm0, xmm0 ; xmm0 = sqrt(dx^2 + dy^2)
    movss [r10], xmm0 ; Store result in z[i]
    add rsi, 4 ; Increment dx pointer
    add rdi, 4 ; Increment dy pointer
    add r10, 4 ; Increment z pointer
    dec rcx ; Decrement counter
    jnz calculate_z_loop ; Loop if not zero
calculate_z_done:
    ret
