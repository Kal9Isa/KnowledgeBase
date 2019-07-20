CREATE DATABASE Healthcare;

USE Healthcare;

CREATE TABLE services (
    id INTEGER NOT NULL,
    title VARCHAR(100),
    PRIMARY KEY (id)
);

INSERT INTO services (id, title) VALUES (1, "CT Scan");
INSERT INTO services (id, title) VALUES (2, "Sonography");
INSERT INTO services (id, title) VALUES (3, "Blood Test");
INSERT INTO services (id, title) VALUES (4, "MRI");

CREATE TABLE patients (
    pid INTEGER NOT NULL ,
    nid VARCHAR(10) NOT NULL UNIQUE,
    srvReceived INTEGER REFERENCES services(id),
    PRIMARY KEY (pid)
);

INSERT INTO patients (pid ,nid, srvReceived) VALUES (1, "0019546762", 1);
INSERT INTO patients (pid ,nid, srvReceived) VALUES (2, "0019547342", 4);
INSERT INTO patients (pid ,nid, srvReceived) VALUES (3, "0045546762", 3);
INSERT INTO patients (pid ,nid, srvReceived) VALUES (1, "0045546762", 2);
INSERT INTO patients (pid ,nid, srvReceived) VALUES (4, "0017443806", 1);
INSERT INTO patients (pid ,nid, srvReceived) VALUES (5, "0019546000", 3);
INSERT INTO patients (pid ,nid, srvReceived) VALUES (6, "0019548902", 1);
INSERT INTO patients (pid ,nid, srvReceived) VALUES (6, "0019548902", 2);
INSERT INTO patients (pid ,nid, srvReceived) VALUES (6, "0019548902", 3);
INSERT INTO patients (pid ,nid, srvReceived) VALUES (7, "0278656762", 3);
INSERT INTO patients (pid ,nid, srvReceived) VALUES (7, "0278656762", 2);
INSERT INTO patients (pid ,nid, srvReceived) VALUES (7, "0278656762", 1);
INSERT INTO patients (pid ,nid, srvReceived) VALUES (8, "0019586762", 3);
INSERT INTO patients (pid ,nid, srvReceived) VALUES (8, "0019586762", 1);
INSERT INTO patients (pid ,nid, srvReceived) VALUES (9, "0035676762", 3);
INSERT INTO patients (pid ,nid, srvReceived) VALUES (10, "0019348762", 4);

