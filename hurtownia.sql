SET SQL_MODE="NO_AUTO_VALUE_ON_ZERO";

# zmienione kodowanie na UTF-8
# zmienione atrybuty: `vat`, `regon`

CREATE TABLE IF NOT EXISTS `Sklep` (
  `id` int(8) unsigned NOT NULL AUTO_INCREMENT,
  `regon` varchar(9) NOT NULL,
  `nazwa` varchar(30) NOT NULL,
  `upust` float DEFAULT NULL,
  `login` varchar(12) NOT NULL,
  `haslo` varchar(20) NOT NULL,
  `ulica` varchar(30) NOT NULL,
  `miejscowosc` varchar(20) NOT NULL,
  `kodPocztowy` varchar(5) NOT NULL,
  `telefon` varchar(9) NOT NULL,
  `fax` varchar(9) DEFAULT NULL,
  `email` varchar(30) DEFAULT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 AUTO_INCREMENT=1 ;
INSERT INTO `Sklep` (`nazwa`, `upust`, `login`, `haslo`) VALUES
('Osiv Sklep',5.5, 'osiv', '1');

CREATE TABLE IF NOT EXISTS `Kategoria` (
  `id`  int(8) unsigned NOT NULL AUTO_INCREMENT,
  `nazwa` varchar(50) NOT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

INSERT INTO `Kategoria` (`nazwa`) VALUES
('Art. spożywcze'),
('Sprzęt'),
('Broń'),
('Papiernicze');

CREATE TABLE IF NOT EXISTS `Towar` (
  `id` int(8) unsigned NOT NULL AUTO_INCREMENT,
  `nazwa` varchar(50) NOT NULL,
  `opis` varchar(150) DEFAULT NULL,
  `cena` float NOT NULL,
  `ilosc` int(11) NOT NULL,
  `idKategorii` int(8) unsigned NOT NULL,
  FOREIGN KEY (idKategorii) REFERENCES Kategoria(id),
  `vat` enum('VAT0','VAT3','VAT7','VAT14','VAT22') NOT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB  DEFAULT CHARSET=utf8 AUTO_INCREMENT=1 ;

INSERT INTO `Towar` (`Nazwa`, `opis`, `cena`, `ilosc`, `idKategorii`, `vat`) VALUES
('Wódka', '0.5L', '22.45', '66', '1', 'VAT7'),
('Ogórki', '1L', '5', '10', '1', 'VAT22'),
('Myszka', 'Logitech', '69.50', '8', '2', 'VAT22'),
('Orzechy', 'Felix', '3', '25', '1', 'VAT22'),
('Nożyczki', 'Tnix', '7', '63', '4', 'VAT14');


CREATE TABLE IF NOT EXISTS `Zamowienie` (
  `id` int(8) unsigned NOT NULL AUTO_INCREMENT,
  `idSklepu` int(8) unsigned NOT NULL,
  `dataZlozenia` date NOT NULL,
  `dataRealizacji` date DEFAULT NULL,
  `upust` float DEFAULT NULL,
  `status` enum('Oczekujace','Anulowane','DoRealizacji','Zrealizowane') NOT NULL,
  `nrFaktury` varchar(8) DEFAULT NULL,
  PRIMARY KEY (`id`),
  FOREIGN KEY (idSklepu) REFERENCES Sklep(id)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 AUTO_INCREMENT=1 ;


CREATE TABLE IF NOT EXISTS `Pozycja_zamowienia` (
  `id` int(8) unsigned NOT NULL AUTO_INCREMENT,
  `idZamowienia` int(8) unsigned NOT NULL,
  `idTowaru` int(8) unsigned NOT NULL,
  `ilosc` int(11) NOT NULL,
  PRIMARY KEY (`id`),
  FOREIGN KEY (idZamowienia) REFERENCES Zamowienie(id),
  FOREIGN KEY (idTowaru) REFERENCES Towar(id)
) ENGINE=InnoDB  DEFAULT CHARSET=utf8 AUTO_INCREMENT=1 ;
