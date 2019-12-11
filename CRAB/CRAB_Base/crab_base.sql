-- Base de  donnée du cas CRAB 
-- Crée le 21/11/2019 par J.Mainard

CREATE TABLE `station`(`statNum` INTEGER,`statRue` VARCHAR(50),`statLatitude` FLOAT,`statLongitude` VARCHAR(50),`statMiseEnService` DATE,`statRevision` DATE,primary key(`statNum`));

CREATE TABLE `usager`(`usagerNum` INTEGER,`usagerNom` VARCHAR(50),`usagerPrenom` VARCHAR(50),`usagerTelMobile` VARCHAR(10),`usagerTelFixe` VARCHAR(10),`usagerVille` VARCHAR(50),`usagerCP` VARCHAR(5),`usagerRue` VARCHAR(50),`usagerMail` VARCHAR(50),primary key(`usagerNum`));

CREATE TABLE `batterie`(`batNum` INTEGER,`batRef` VARCHAR(75),`batCapacite` FLOAT,`batFabricant` VARCHAR(50),primary key(`batNum`));

CREATE TABLE `contrat`(`contratNum` INTEGER,primary key(`contratNum`));

CREATE TABLE `typeBorne`(`typeBorneCode` VARCHAR(3),`dureeRevision` INTEGER,`nbJoursEntreRevision` INTEGER,`nbUnitesEntreRevision` INTEGER,primary key(`typeBorneCode`));

CREATE TABLE `forfait`(`forfaitNum` INTEGER,`libelleforfait` VARCHAR(25),`contratNum` INTEGER NOT NULL, foreign key (`contratNum`) references contrat(`contratNum`),primary key(`forfaitNum`));

CREATE TABLE `abonnement`(`aboNum` INTEGER,`aboDateDebut` DATE,`aboDateFin` DATE,`contratNum` INTEGER NOT NULL, foreign key (`contratNum`) references contrat(`contratNum`),primary key(`aboNum`));

CREATE TABLE `echec`(`echecNum` INTEGER,`echecLib` VARCHAR(25),primary key(`echecNum`));

CREATE TABLE `technicien`(`techNum` INTEGER,`techNom` VARCHAR(30),`techPrenom` VARCHAR(30),`techPwd` VARCHAR(150),`techLogin` VARCHAR(20),primary key(`techNum`));

CREATE TABLE `typeIncident`(`typeIncidentNum` INTEGER,`typeIncidentLib` VARCHAR(75),`typeIncidentTempsReparation` INTEGER,primary key(`typeIncidentNum`));

CREATE TABLE `visite`(`visiteNum` INTEGER,`visiteDuree` INTEGER,`visiteEtat` VARCHAR(1),`visiteDate` DATE,`techNum` INTEGER NOT NULL,`statNum` INTEGER NOT NULL, foreign key (`techNum`) references technicien(`techNum`), foreign key (`statNum`) references station(`statNum`),primary key(`visiteNum`));

CREATE TABLE `typeCharge`(`typeChargeNum` INTEGER,`typeChargeLib` VARCHAR(20),`typeChargePuissance` INTEGER,primary key(`typeChargeNum`));

CREATE TABLE `supporte`(`batNum` INTEGER NOT NULL,`typeChargeNum` INTEGER NOT NULL, foreign key (`batNum`) references batterie(`batNum`), foreign key (`typeChargeNum`) references typeCharge(`typeChargeNum`),primary key(`batNum`,`typeChargeNum`));

CREATE TABLE `borne`(`borneNum` INTEGER,`borneEtat` VARCHAR(2),`borneDateMiseEnService` DATE,`borneDerniereRevision` DATE,`borneIndiceCompteurUnite` INTEGER,`statNum` INTEGER NOT NULL,`typeBorneCode` VARCHAR(3) NOT NULL,`typeChargeNum` INTEGER NOT NULL, foreign key (`statNum`) references station(`statNum`), foreign key (`typeBorneCode`) references typeBorne(`typeBorneCode`), foreign key (`typeChargeNum`) references typeCharge(`typeChargeNum`),primary key(`borneNum`));

CREATE TABLE `voiture`(`voitNum` INTEGER,`voitImmatriculation` VARCHAR(9),`batNum` INTEGER NOT NULL,`usagerNum` INTEGER NOT NULL,`contratNum` INTEGER NOT NULL, foreign key (`batNum`) references batterie(`batNum`), foreign key (`usagerNum`) references usager(`usagerNum`), foreign key (`contratNum`) references contrat(`contratNum`),primary key(`voitNum`));

CREATE TABLE `rechargement`(`rechNum` INTEGER,`rechDateDebut` DATE,`rechDateFin` DATE,`rechKwUtilise` FLOAT,`contratNum` INTEGER ,`echecNum` INTEGER , foreign key (`contratNum`) references contrat(`contratNum`), foreign key (`echecNum`) references echec(`echecNum`),primary key(`rechNum`));

CREATE TABLE `incident`(`incidentNum` INTEGER,`incidentRemarque` VARCHAR(75),`incidentdateHeure` DATETIME,`incidentdateHeureCloture` DATETIME,`borneNum` INTEGER NOT NULL,`typeIncidentNum` INTEGER NOT NULL, foreign key (`borneNum`) references borne(`borneNum`), foreign key (`typeIncidentNum`) references typeIncident(`typeIncidentNum`),primary key(`incidentNum`));

CREATE TABLE `intervention`(`interNum` INTEGER,`interDateHeureDebut` DATETIME,`interDateHeureFin` DATETIME,`techNum` INTEGER NOT NULL,`incidentNum` INTEGER NOT NULL, foreign key (`techNum`) references technicien(`techNum`), foreign key (`incidentNum`) references incident(`incidentNum`),primary key(`interNum`));

CREATE TABLE `concerne`(`borneNum` INTEGER NOT NULL,`visiteNum` INTEGER NOT NULL, foreign key (`borneNum`) references borne(`borneNum`), foreign key (`visiteNum`) references visite(`visiteNum`),primary key(`borneNum`,`visiteNum`));


