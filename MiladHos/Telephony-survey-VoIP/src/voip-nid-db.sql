CREATE DATABASE Healthcare;

USE Healthcare;

CREATE TABLE gender (
    gid INTEGER NOT NULL,
    gtitle VARCHAR(1) NOT NULL,
    PRIMARY KEY (gid)
);

CREATE TABLE services (
    service_id INTEGER NOT NULL,
    title VARCHAR(100),
    PRIMARY KEY (service_id)
);

CREATE TABLE patients (
    patient_id VARCHAR(10) NOT NULL UNIQUE,
    p_gender INTEGER REFERENCES gender(gid),
    p_name VARCHAR(50) NOT NULL,
    p_surname VARCHAR(50) NOT NULL,
    p_age INTEGER NOT NULL,
    PRIMARY KEY (patient_id)
);

CREATE TABLE patientsServices (
    listNum INTEGER NOT NULL AUTO_INCREMENT,
    patient_treated VARCHAR(10) REFERENCES patients(patient_id),
    service_received INTEGER REFERENCES services(service_id),
    PRIMARY KEY (listNum)
);

INSERT INTO gender (gid, gtitle) VALUES (0, "M"); 
INSERT INTO gender (gid, gtitle) VALUES (1, "F"); 

INSERT INTO services (service_id, title) VALUES (1, "CT Scan");
INSERT INTO services (service_id, title) VALUES (2, "Sonography");
INSERT INTO services (service_id, title) VALUES (3, "Blood Test");
INSERT INTO services (service_id, title) VALUES (4, "MRI");

INSERT INTO patients (patient_id, p_gender ,p_name, p_surname, p_age) VALUES ("0019546762", 0, "Arvin", "Rahmani", 56);
INSERT INTO patients (patient_id, p_gender ,p_name, p_surname, p_age) VALUES ("0019547342", 0,"Hamid", "Saeidi", 21);
INSERT INTO patients (patient_id, p_gender ,p_name, p_surname, p_age) VALUES ("0045546762", 1, "Maryam", "Fazli", 34);
INSERT INTO patients (patient_id, p_gender ,p_name, p_surname, p_age) VALUES ("0017443806", 1, "Zahra", "Safavi", 29);
INSERT INTO patients (patient_id, p_gender ,p_name, p_surname, p_age) VALUES ("0019546000", 0, "Saeid", "Saajedi", 33);
INSERT INTO patients (patient_id, p_gender ,p_name, p_surname, p_age) VALUES ("0019548902", 0, "Reza", "Ghafouri", 50);
INSERT INTO patients (patient_id, p_gender ,p_name, p_surname, p_age) VALUES ("0278656762", 0, "Milad", "Parsa", 18);
INSERT INTO patients (patient_id, p_gender ,p_name, p_surname, p_age) VALUES ("0019586762", 1, "Nooshin", "Kamkar", 42);
INSERT INTO patients (patient_id, p_gender ,p_name, p_surname, p_age) VALUES ("0035676762", 0, "Karim", "Mottaghi", 41);
INSERT INTO patients (patient_id, p_gender ,p_name, p_surname, p_age) VALUES ("0019348762", 1, "Raha", "Shokoohi", 30);
INSERT INTO patients (patient_id, p_gender ,p_name, p_surname, p_age) VALUES ("0019348999", 0, "Masoud", "Saberi", 25);

INSERT INTO patientsServices (patient_treated, service_received) VALUES ("0019546762", 1);
INSERT INTO patientsServices (patient_treated, service_received) VALUES ("0019547342", 4);
INSERT INTO patientsServices (patient_treated, service_received) VALUES ("0045546762", 3);
INSERT INTO patientsServices (patient_treated, service_received) VALUES ("0045546762", 2);
INSERT INTO patientsServices (patient_treated, service_received) VALUES ("0017443806", 1);
INSERT INTO patientsServices (patient_treated, service_received) VALUES ("0019546000", 3);
INSERT INTO patientsServices (patient_treated, service_received) VALUES ("0019548902", 1);
INSERT INTO patientsServices (patient_treated, service_received) VALUES ("0019548902", 2);
INSERT INTO patientsServices (patient_treated, service_received) VALUES ("0019548902", 3);
INSERT INTO patientsServices (patient_treated, service_received) VALUES ("0278656762", 3);
INSERT INTO patientsServices (patient_treated, service_received) VALUES ("0278656762", 2);
INSERT INTO patientsServices (patient_treated, service_received) VALUES ("0278656762", 1);
INSERT INTO patientsServices (patient_treated, service_received) VALUES ("0019586762", 3);
INSERT INTO patientsServices (patient_treated, service_received) VALUES ("0019586762", 1);
INSERT INTO patientsServices (patient_treated, service_received) VALUES ("0035676762", 3);
INSERT INTO patientsServices (patient_treated, service_received) VALUES ("0019348762", 4);
INSERT INTO patientsServices (patient_treated, service_received) VALUES ("0019348999", 4);

