       IDENTIFICATION DIVISION.
       PROGRAM-ID. second.

       DATA DIVISION.
       WORKING-STORAGE SECTION.
       01 Num PIC 9(3).
       01 MAIOR PIC 9(3) VALUE 50.

       PROCEDURE DIVISION.
       

           DISPLAY  "MAIOR OU MENOR"
           DISPLAY ""
           DISPLAY "DIGITE UM NUMERO: "
           ACCEPT Num

           IF Num > MAIOR THEN
               DISPLAY "O NUMERO DIGITADO É MAIOR QUE 50."

           ELSE IF Num < MAIOR THEN
               DISPLAY "O NUMERO DIGITADO É MENOR QUE 50."

           ELSE 
               DISPLAY "O NUMERO DIGITADO É IGUAL A 50." 

           END-IF 

           STOP RUN.


