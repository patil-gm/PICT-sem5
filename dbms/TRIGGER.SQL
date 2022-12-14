-- FEW INBUILD FUNCTION THAT ARE USED IN TRIGGERS TO KEEP RECORD 
-- NOW()   --> THE TIMESTAMP AT WHICH THE UPDATION IS DONE : TYPE - DATETIME
-- CURDATE --> THE TODAYS DATE                             : TYPE - DATE
-- CURRENT_USER() --> WHO IS USING THE DATABASE            : TYPE - VARCHAR(255)

CREATE TRIGGER trigger_name
AFTER UPDATE ON TEBLE_NAME -- YOU SHOULD HAVE INCLUDE THE OPRATION THAT YOU ARE GOING TO PERFORM AND STORE THE RECORDS
FOR EACH ROW 

BEGIN
-- QUERI TO STORE THE RECORD UPDATED
INSERT INTO RECORD_TABLE_NAME VALUES (OLD.PAR1,OLD.PAR2,OLD.PAR3, NOW(),'UPDATE');
END;
//


--******************* UPDATE TRIGGER *******************--

CREATE TRIGGER trigger_name
AFTER UPDATE ON UP_TEBLE_NAME
FOR EACH ROW 

BEGIN
-- QUERI TO STORE THE RECORD UPDATED
INSERT INTO RECORD_TABLE_NAME VALUES (OLD.PAR1,OLD.PAR2,OLD.PAR3, NOW(),'UPADTE');
END;
//


--******************* DELETE TRIGGER *******************--

CREATE TRIGGER trigger_name
AFTER DELETE ON DL_TEBLE_NAME
FOR EACH ROW 

BEGIN
-- QUERI TO STORE THE RECORD DELETED
INSERT INTO RECORD_TABLE_NAME VALUES (OLD.PAR1,OLD.PAR2,OLD.PAR3, NOW(),'DELETE');
END;
//
