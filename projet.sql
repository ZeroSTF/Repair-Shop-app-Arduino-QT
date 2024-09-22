--------------------------------------------------------
--  File created - Wednesday-December-08-2021   
--------------------------------------------------------
DROP TABLE "VEHICULE";
DROP TABLE "STAFF";
DROP TABLE "INTERVENTION";
DROP TABLE "EQUIPEMENT";
DROP TABLE "CLIENT";
DROP TABLE "AFFECTER";
--------------------------------------------------------
--  DDL for Sequence INTERVENTION_SEQ1
--------------------------------------------------------

   CREATE SEQUENCE  "INTERVENTION_SEQ1"  MINVALUE 1 MAXVALUE 9999999999999999999999999999 INCREMENT BY 1 START WITH 21 CACHE 20 NOORDER  NOCYCLE ;
--------------------------------------------------------
--  DDL for Sequence EQUIPEMENT_SEQ
--------------------------------------------------------

   CREATE SEQUENCE  "EQUIPEMENT_SEQ"  MINVALUE 1 MAXVALUE 9999999999999999999999999999 INCREMENT BY 1 START WITH 1 CACHE 20 NOORDER  NOCYCLE ;
--------------------------------------------------------
--  DDL for Table VEHICULE
--------------------------------------------------------

  CREATE TABLE "VEHICULE" 
   (	"NUMERO" NUMBER, 
	"MARQUE" VARCHAR2(20 BYTE), 
	"KILOMETRAGE" NUMBER, 
	"COULEUR" VARCHAR2(20 BYTE), 
	"CIN" NUMBER
   ) SEGMENT CREATION IMMEDIATE 
  PCTFREE 10 PCTUSED 40 INITRANS 1 MAXTRANS 255 NOCOMPRESS LOGGING
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM" ;
--------------------------------------------------------
--  DDL for Table STAFF
--------------------------------------------------------

  CREATE TABLE "STAFF" 
   (	"ID" VARCHAR2(20 BYTE), 
	"NOM" VARCHAR2(20 BYTE), 
	"PRENOM" VARCHAR2(20 BYTE), 
	"FONCTION" VARCHAR2(20 BYTE), 
	"DATE_NAISSANCE" DATE
   ) SEGMENT CREATION IMMEDIATE 
  PCTFREE 10 PCTUSED 40 INITRANS 1 MAXTRANS 255 NOCOMPRESS LOGGING
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM" ;
--------------------------------------------------------
--  DDL for Table INTERVENTION
--------------------------------------------------------

  CREATE TABLE "INTERVENTION" 
   (	"ID" NUMBER, 
	"TYPE" VARCHAR2(20 BYTE), 
	"DATE_INT" DATE, 
	"ID_EMPLOYE" VARCHAR2(20 BYTE), 
	"NUM_SERIE" NUMBER(*,0)
   ) SEGMENT CREATION IMMEDIATE 
  PCTFREE 10 PCTUSED 40 INITRANS 1 MAXTRANS 255 NOCOMPRESS LOGGING
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM" ;
--------------------------------------------------------
--  DDL for Table EQUIPEMENT
--------------------------------------------------------

  CREATE TABLE "EQUIPEMENT" 
   (	"IDENTIFIENT_EQ" VARCHAR2(20 BYTE), 
	"NOM_EQ" VARCHAR2(20 BYTE), 
	"MARQUE_EQ" VARCHAR2(20 BYTE), 
	"QUANTITE_EQ" VARCHAR2(20 BYTE)
   ) SEGMENT CREATION IMMEDIATE 
  PCTFREE 10 PCTUSED 40 INITRANS 1 MAXTRANS 255 NOCOMPRESS LOGGING
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM" ;
--------------------------------------------------------
--  DDL for Table CLIENT
--------------------------------------------------------

  CREATE TABLE "CLIENT" 
   (	"CIN" NUMBER, 
	"NOM" VARCHAR2(20 BYTE), 
	"PRENOM" VARCHAR2(20 BYTE), 
	"TEL" NUMBER, 
	"VILLE" VARCHAR2(20 BYTE)
   ) SEGMENT CREATION IMMEDIATE 
  PCTFREE 10 PCTUSED 40 INITRANS 1 MAXTRANS 255 NOCOMPRESS LOGGING
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM" ;
--------------------------------------------------------
--  DDL for Table AFFECTER
--------------------------------------------------------

  CREATE TABLE "AFFECTER" 
   (	"ID_EQUIPEMENT" VARCHAR2(20 BYTE), 
	"ID_INTERVENTION" NUMBER
   ) SEGMENT CREATION IMMEDIATE 
  PCTFREE 10 PCTUSED 40 INITRANS 1 MAXTRANS 255 NOCOMPRESS LOGGING
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM" ;
REM INSERTING into ZEROS.VEHICULE
SET DEFINE OFF;
Insert into ZEROS.VEHICULE (NUMERO,MARQUE,KILOMETRAGE,COULEUR,CIN) values (111,'volswagen',1,'rouge',1111);
Insert into ZEROS.VEHICULE (NUMERO,MARQUE,KILOMETRAGE,COULEUR,CIN) values (112,'golf 2',2,'vert',1112);
REM INSERTING into ZEROS.STAFF
SET DEFINE OFF;
Insert into ZEROS.STAFF (ID,NOM,PRENOM,FONCTION,DATE_NAISSANCE) values ('id_emp','chnitir','riadh','ingenieur',null);
Insert into ZEROS.STAFF (ID,NOM,PRENOM,FONCTION,DATE_NAISSANCE) values ('id emp 1','jery','fyras','technicien',null);
Insert into ZEROS.STAFF (ID,NOM,PRENOM,FONCTION,DATE_NAISSANCE) values ('3','r','c','Technicien',to_date('01-JAN-00','DD-MON-RR'));
Insert into ZEROS.STAFF (ID,NOM,PRENOM,FONCTION,DATE_NAISSANCE) values ('4','r','c','Ingenieur',to_date('01-JAN-00','DD-MON-RR'));
Insert into ZEROS.STAFF (ID,NOM,PRENOM,FONCTION,DATE_NAISSANCE) values ('5','r','c','Staff',to_date('01-JAN-00','DD-MON-RR'));
Insert into ZEROS.STAFF (ID,NOM,PRENOM,FONCTION,DATE_NAISSANCE) values ('6','omar','abd','Staff',to_date('01-JAN-00','DD-MON-RR'));
Insert into ZEROS.STAFF (ID,NOM,PRENOM,FONCTION,DATE_NAISSANCE) values ('7','omar','abd','Staff',to_date('01-JAN-00','DD-MON-RR'));
Insert into ZEROS.STAFF (ID,NOM,PRENOM,FONCTION,DATE_NAISSANCE) values ('200','omar','abd','Ingenieur',to_date('01-JAN-00','DD-MON-RR'));
REM INSERTING into ZEROS.INTERVENTION
SET DEFINE OFF;
Insert into ZEROS.INTERVENTION (ID,TYPE,DATE_INT,ID_EMPLOYE,NUM_SERIE) values (63,'Service Rapide',to_date('01-JAN-24','DD-MON-RR'),'id emp 1',112);
Insert into ZEROS.INTERVENTION (ID,TYPE,DATE_INT,ID_EMPLOYE,NUM_SERIE) values (2,'Service Rapide',to_date('01-JAN-00','DD-MON-RR'),'id_emp',111);
Insert into ZEROS.INTERVENTION (ID,TYPE,DATE_INT,ID_EMPLOYE,NUM_SERIE) values (49,'Service Rapide',to_date('01-JAN-00','DD-MON-RR'),'id_emp',111);
Insert into ZEROS.INTERVENTION (ID,TYPE,DATE_INT,ID_EMPLOYE,NUM_SERIE) values (3,'Service Rapide',to_date('01-JAN-00','DD-MON-RR'),'id_emp',111);
Insert into ZEROS.INTERVENTION (ID,TYPE,DATE_INT,ID_EMPLOYE,NUM_SERIE) values (1,'Service Rapide',to_date('01-JAN-00','DD-MON-RR'),'id_emp',111);
Insert into ZEROS.INTERVENTION (ID,TYPE,DATE_INT,ID_EMPLOYE,NUM_SERIE) values (62,'Maintenance',to_date('01-JAN-00','DD-MON-RR'),'id_emp',111);
Insert into ZEROS.INTERVENTION (ID,TYPE,DATE_INT,ID_EMPLOYE,NUM_SERIE) values (81,'Service Rapide',to_date('01-JAN-25','DD-MON-RR'),'id emp 1',112);
Insert into ZEROS.INTERVENTION (ID,TYPE,DATE_INT,ID_EMPLOYE,NUM_SERIE) values (65,'Maintenance',to_date('01-JAN-00','DD-MON-RR'),'id_emp',111);
Insert into ZEROS.INTERVENTION (ID,TYPE,DATE_INT,ID_EMPLOYE,NUM_SERIE) values (82,'Maintenance',to_date('01-JAN-00','DD-MON-RR'),'id_emp',111);
Insert into ZEROS.INTERVENTION (ID,TYPE,DATE_INT,ID_EMPLOYE,NUM_SERIE) values (4,'Service Rapide',to_date('01-JAN-00','DD-MON-RR'),'id_emp',111);
REM INSERTING into ZEROS.EQUIPEMENT
SET DEFINE OFF;
REM INSERTING into ZEROS.CLIENT
SET DEFINE OFF;
Insert into ZEROS.CLIENT (CIN,NOM,PRENOM,TEL,VILLE) values (1111,'biden','joe',51591222,'fdar');
Insert into ZEROS.CLIENT (CIN,NOM,PRENOM,TEL,VILLE) values (1112,'bodoldjob','michel',51591232,'fdarhom');
REM INSERTING into ZEROS.AFFECTER
SET DEFINE OFF;
--------------------------------------------------------
--  DDL for Index VEHICULE_PK
--------------------------------------------------------

  CREATE UNIQUE INDEX "VEHICULE_PK" ON "VEHICULE" ("NUMERO") 
  PCTFREE 10 INITRANS 2 MAXTRANS 255 COMPUTE STATISTICS 
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM" ;
--------------------------------------------------------
--  DDL for Index EMPLOYE_PK
--------------------------------------------------------

  CREATE UNIQUE INDEX "EMPLOYE_PK" ON "STAFF" ("ID") 
  PCTFREE 10 INITRANS 2 MAXTRANS 255 COMPUTE STATISTICS 
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM" ;
--------------------------------------------------------
--  DDL for Index INTERVENTION_PK
--------------------------------------------------------

  CREATE UNIQUE INDEX "INTERVENTION_PK" ON "INTERVENTION" ("ID") 
  PCTFREE 10 INITRANS 2 MAXTRANS 255 COMPUTE STATISTICS 
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM" ;
--------------------------------------------------------
--  DDL for Index EQUIPEMENT_PK
--------------------------------------------------------

  CREATE UNIQUE INDEX "EQUIPEMENT_PK" ON "EQUIPEMENT" ("IDENTIFIENT_EQ") 
  PCTFREE 10 INITRANS 2 MAXTRANS 255 COMPUTE STATISTICS 
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM" ;
--------------------------------------------------------
--  DDL for Index CLIENT_PK
--------------------------------------------------------

  CREATE UNIQUE INDEX "CLIENT_PK" ON "CLIENT" ("CIN") 
  PCTFREE 10 INITRANS 2 MAXTRANS 255 COMPUTE STATISTICS 
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM" ;
--------------------------------------------------------
--  DDL for Index AFFECTER_PK
--------------------------------------------------------

  CREATE UNIQUE INDEX "AFFECTER_PK" ON "AFFECTER" ("ID_EQUIPEMENT", "ID_INTERVENTION") 
  PCTFREE 10 INITRANS 2 MAXTRANS 255 COMPUTE STATISTICS 
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM" ;
--------------------------------------------------------
--  DDL for Trigger INTERVENTION_TRG
--------------------------------------------------------

  CREATE OR REPLACE TRIGGER "INTERVENTION_TRG" 
BEFORE INSERT ON INTERVENTION 
FOR EACH ROW 
BEGIN
  <<COLUMN_SEQUENCES>>
  BEGIN
    NULL;
  END COLUMN_SEQUENCES;
END;
/
ALTER TRIGGER "INTERVENTION_TRG" ENABLE;
--------------------------------------------------------
--  DDL for Trigger INTERVENTION_TRG1
--------------------------------------------------------

  CREATE OR REPLACE TRIGGER "INTERVENTION_TRG1" 
BEFORE INSERT ON INTERVENTION 
FOR EACH ROW 
BEGIN
  <<COLUMN_SEQUENCES>>
  BEGIN
    IF INSERTING AND :NEW.ID IS NULL THEN
      SELECT INTERVENTION_SEQ1.NEXTVAL INTO :NEW.ID FROM SYS.DUAL;
    END IF;
  END COLUMN_SEQUENCES;
END;
/
ALTER TRIGGER "INTERVENTION_TRG1" ENABLE;
--------------------------------------------------------
--  DDL for Trigger EQUIPEMENT_TRG
--------------------------------------------------------

  CREATE OR REPLACE TRIGGER "EQUIPEMENT_TRG" 
BEFORE INSERT ON EQUIPEMENT 
FOR EACH ROW 
BEGIN
  <<COLUMN_SEQUENCES>>
  BEGIN
    IF INSERTING AND :NEW.IDENTIFIENT_EQ IS NULL THEN
      SELECT EQUIPEMENT_SEQ.NEXTVAL INTO :NEW.IDENTIFIENT_EQ FROM SYS.DUAL;
    END IF;
  END COLUMN_SEQUENCES;
END;
/
ALTER TRIGGER "EQUIPEMENT_TRG" ENABLE;
--------------------------------------------------------
--  Constraints for Table VEHICULE
--------------------------------------------------------

  ALTER TABLE "VEHICULE" ADD CONSTRAINT "VEHICULE_PK" PRIMARY KEY ("NUMERO")
  USING INDEX PCTFREE 10 INITRANS 2 MAXTRANS 255 COMPUTE STATISTICS 
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM"  ENABLE;
  ALTER TABLE "VEHICULE" MODIFY ("NUMERO" NOT NULL ENABLE);
--------------------------------------------------------
--  Constraints for Table STAFF
--------------------------------------------------------

  ALTER TABLE "STAFF" ADD CONSTRAINT "EMPLOYE_PK" PRIMARY KEY ("ID")
  USING INDEX PCTFREE 10 INITRANS 2 MAXTRANS 255 COMPUTE STATISTICS 
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM"  ENABLE;
  ALTER TABLE "STAFF" MODIFY ("ID" NOT NULL ENABLE);
--------------------------------------------------------
--  Constraints for Table INTERVENTION
--------------------------------------------------------

  ALTER TABLE "INTERVENTION" MODIFY ("ID_EMPLOYE" NOT NULL ENABLE);
  ALTER TABLE "INTERVENTION" ADD CONSTRAINT "INTERVENTION_PK" PRIMARY KEY ("ID")
  USING INDEX PCTFREE 10 INITRANS 2 MAXTRANS 255 COMPUTE STATISTICS 
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM"  ENABLE;
  ALTER TABLE "INTERVENTION" MODIFY ("ID" NOT NULL ENABLE);
--------------------------------------------------------
--  Constraints for Table EQUIPEMENT
--------------------------------------------------------

  ALTER TABLE "EQUIPEMENT" ADD CONSTRAINT "EQUIPEMENT_PK" PRIMARY KEY ("IDENTIFIENT_EQ")
  USING INDEX PCTFREE 10 INITRANS 2 MAXTRANS 255 COMPUTE STATISTICS 
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM"  ENABLE;
  ALTER TABLE "EQUIPEMENT" MODIFY ("IDENTIFIENT_EQ" NOT NULL ENABLE);
--------------------------------------------------------
--  Constraints for Table CLIENT
--------------------------------------------------------

  ALTER TABLE "CLIENT" ADD CONSTRAINT "CLIENT_PK" PRIMARY KEY ("CIN")
  USING INDEX PCTFREE 10 INITRANS 2 MAXTRANS 255 COMPUTE STATISTICS 
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM"  ENABLE;
  ALTER TABLE "CLIENT" MODIFY ("CIN" NOT NULL ENABLE);
--------------------------------------------------------
--  Constraints for Table AFFECTER
--------------------------------------------------------

  ALTER TABLE "AFFECTER" ADD CONSTRAINT "AFFECTER_PK" PRIMARY KEY ("ID_EQUIPEMENT", "ID_INTERVENTION")
  USING INDEX PCTFREE 10 INITRANS 2 MAXTRANS 255 COMPUTE STATISTICS 
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM"  ENABLE;
  ALTER TABLE "AFFECTER" MODIFY ("ID_INTERVENTION" NOT NULL ENABLE);
--------------------------------------------------------
--  Ref Constraints for Table VEHICULE
--------------------------------------------------------

  ALTER TABLE "VEHICULE" ADD CONSTRAINT "POSSEDER" FOREIGN KEY ("CIN")
	  REFERENCES "CLIENT" ("CIN") ENABLE;
--------------------------------------------------------
--  Ref Constraints for Table INTERVENTION
--------------------------------------------------------

  ALTER TABLE "INTERVENTION" ADD CONSTRAINT "APPLIQUER" FOREIGN KEY ("NUM_SERIE")
	  REFERENCES "VEHICULE" ("NUMERO") ENABLE;
  ALTER TABLE "INTERVENTION" ADD CONSTRAINT "FAIRE" FOREIGN KEY ("ID_EMPLOYE")
	  REFERENCES "STAFF" ("ID") ENABLE;
--------------------------------------------------------
--  Ref Constraints for Table AFFECTER
--------------------------------------------------------

  ALTER TABLE "AFFECTER" ADD CONSTRAINT "AFFECTER_FK1" FOREIGN KEY ("ID_EQUIPEMENT")
	  REFERENCES "EQUIPEMENT" ("IDENTIFIENT_EQ") ENABLE;
  ALTER TABLE "AFFECTER" ADD CONSTRAINT "AFFECTER_FK2" FOREIGN KEY ("ID_INTERVENTION")
	  REFERENCES "INTERVENTION" ("ID") ENABLE;
