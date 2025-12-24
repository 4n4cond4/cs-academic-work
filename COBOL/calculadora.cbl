       IDENTIFICATION DIVISION.
       PROGRAM-ID. calculadora.

       DATA DIVISION.
       WORKING-STORAGE SECTION.
      
       01 A PIC 9(5)V99 VALUE 0.
       01 B PIC 9(5)V99 VALUE 0.
       01 SOMA PIC 9(2)V99.
       01 SUB PIC 9(2)V99.
       01 MULT PIC 9(2)V99.
       01 DIV PIC 9(2)V99.
       01 ESCOLHE PIC X.
       
       PROCEDURE DIVISION.
       DISPLAY "=============================="
       DISPLAY "CALCULADORA"
       DISPLAY "=============================="
       DISPLAY " "

       DISPLAY "DIGITE 1 - SOMA/ 2 - SUBTRAÇÃO"
       DISPLAY "/ 3 - MULTIPLICAÇAO/ 4 - DIVISÃO"
       ACCEPT ESCOLHE.
       

       DISPLAY "DIGITE O PRIMEIRO NUMERO INTEIRO: "
       ACCEPT A.
       DISPLAY " "

       DISPLAY "DIGITE O SEGUNDO NUMERO INTEIRO: "
       ACCEPT B.
       DISPLAY " "

      
       EVALUATE ESCOLHE

           WHEN '1'
           COMPUTE SOMA = A + B
           DISPLAY "RESULTADO: " SOMA

           WHEN '2'
           COMPUTE SUB = A - B
           DISPLAY "RESULTADO: " SUB

           WHEN '3'
           COMPUTE MULT = A * B
           DISPLAY "RESULTADO: " MULT

           WHEN '4'
           IF B = 0
           DISPLAY "DIVISÃO INVÁLIDA!"
      
           ELSE
           COMPUTE DIV = A / B
           DISPLAY "RESULTADO: " DIV

           END-IF
           WHEN OTHER
           DISPLAY "OPÇÃO INVÁLIDA!"

       END-EVALUATE. 

       STOP RUN.



