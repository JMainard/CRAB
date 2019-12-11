-- Jeux d'essais Projet CRAB
-- Creer le 20-11-2019 par J.Mainard


insert into station values
(1,'1 Rue carnot',82.5,41.268,'2018-05-19','2019-11-14'),
(2,'34 rue jacqueline Auriol',40.5,4.2,'2018-10-19','2019-11-05'),
(3,'3 rue du Marechal Ferrand',52.5,41.2,'2018-01-05','2019-10-25');

insert into typeBorne values
('V1',4,30,1500),
('V2',2,30,2000),
('V3',2,25,2000),
('V4',3,25,2000);

insert into typeCharge values
(1,'Normal',4),
(2,'Semi-Rapide',15),
(3,'Rapide',33);

insert into borne values
(1,'ES','2018-05-22','2018-11-14',1300,1,'V1',1),
(2,'HS','2018-05-23','2018-11-14',2000,1,'V2',2),
(3,'ES','2018-10-20','2018-11-06',1400,2,'V3',2),
(4,'ES','2018-10-22','2018-11-06',2200,2,'V4',3);



insert into technicien values 
(1,'Calamone','Yoan','5f4dcc3b5aa765d61d8327deb882cf99','jesaispastrop'),
(2,'Brocier','Anto','5f4dcc3b5aa765d61d8327deb882cf99','anto'),
(3,'Meosie','Teo','5f4dcc3b5aa765d61d8327deb882cf99','teo'),
(4,'Du-rent','Luka','5f4dcc3b5aa765d61d8327deb882cf99','luka'),
(5,'BourgBouce','Silvin','5f4dcc3b5aa765d61d8327deb882cf99','silvin');
