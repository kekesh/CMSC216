;;; Organization of typical avr program (; used for comments (don't use #))

;;; Symbolic constants 
        .set LETTER_A, 65      ; Constant for A
        .set NEWLINE, 10       ; Constant for \n

;;; Global data
        .data                  ; Begins data section.
x:      .byte 6                ; Label ``x" stores 6

;;; Program code
        .text                  ;Directive to start code

.global main                   ; Makes main label externally available
main:                          
        ;; main function. Task is defined at this point. This function prints letter A followed by newline character. We need the  newline to force the flushing of character A.  

        call init_serial_stdio ; To call a function we use the call instruction

        ldi r24, LETTER_A   ; The ldi instruction loads a value into a register.
        clr r25 ; Sets high byte of putchar's integer argument to 0.
        call putchar ; Calls putchar to print the character
        
    ldi r24, NEWLINE ; Initializes r24 with '\n' character ascii value
        clr r25 ; Sets high byte of putchar's integer argument to 0
    call putchar 

    cli                    ; We need to stop the program. Relying on cli and sleep. 
        sleep                          

        ret ; Adding this ret to show functions end with ret but this ret is unreachable (program already stopped)