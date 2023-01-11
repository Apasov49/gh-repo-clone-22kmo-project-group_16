CREATE DATABASE  IF NOT EXISTS `group_16` /*!40100 DEFAULT CHARACTER SET utf8mb3 */ /*!80016 DEFAULT ENCRYPTION='N' */;
USE `group_16`;
-- MySQL dump 10.13  Distrib 8.0.30, for Win64 (x86_64)
--
-- Host: 127.0.0.1    Database: group_16
-- ------------------------------------------------------
-- Server version	8.0.29

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!50503 SET NAMES utf8 */;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

--
-- Table structure for table `account`
--

DROP TABLE IF EXISTS `account`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `account` (
  `id_account` int NOT NULL,
  `id_client` int DEFAULT NULL,
  `balance` float DEFAULT NULL,
  PRIMARY KEY (`id_account`),
  KEY `client_account_idx` (`id_client`),
  CONSTRAINT `client_account` FOREIGN KEY (`id_client`) REFERENCES `client` (`id_client`) ON DELETE RESTRICT ON UPDATE CASCADE
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb3;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `account`
--

LOCK TABLES `account` WRITE;
/*!40000 ALTER TABLE `account` DISABLE KEYS */;
INSERT INTO `account` VALUES (1,1,3785.5),(2,1,100259.24),(3,2,1087),(4,2,4045.36),(5,3,44308.88),(6,3,9669.91),(7,4,9105.82),(8,3,2212.95),(9,5,3809.69),(10,5,20000.23);
/*!40000 ALTER TABLE `account` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `card`
--

DROP TABLE IF EXISTS `card`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `card` (
  `id_card` int NOT NULL AUTO_INCREMENT,
  `id_client` int DEFAULT NULL,
  `id_account` int DEFAULT NULL,
  `pin` varchar(255) DEFAULT NULL,
  `card_status` int DEFAULT '0',
  PRIMARY KEY (`id_card`),
  KEY `account_card_idx` (`id_account`),
  KEY `client_card_idx` (`id_client`),
  CONSTRAINT `account_card` FOREIGN KEY (`id_account`) REFERENCES `account` (`id_account`) ON DELETE RESTRICT ON UPDATE CASCADE,
  CONSTRAINT `client_card` FOREIGN KEY (`id_client`) REFERENCES `client` (`id_client`) ON DELETE RESTRICT ON UPDATE CASCADE
) ENGINE=InnoDB AUTO_INCREMENT=11 DEFAULT CHARSET=utf8mb3;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `card`
--

LOCK TABLES `card` WRITE;
/*!40000 ALTER TABLE `card` DISABLE KEYS */;
INSERT INTO `card` VALUES (1,1,1,'$2a$12$ZDeLEqYtmUVpSz4G98CVd.BuYZ3krZ8ROmR61yl5yGwviNRsrL4bK',0),(2,1,2,'$2a$12$I4fw9h58W1YO6Js8GZWW7.H0XEFUiAw45NU6kBSb/.roqGg4odHK.',0),(3,2,3,'$2a$12$06jjl4WZ/BGuA7whFjk0NOGHnRhiBFovQb.Oj4MeUR5jsBQfwwmkW',0),(4,2,4,'$2a$12$HNQwbaENsmNfagumeGJ8GOG6h8R1PRr4OhB4qYfpGoGtMT7x/wjHa',0),(5,3,5,'$2a$12$0CGEyxH4eGB6hffSPQ5Pv.k.BLpL7VIbZ0P.YgIj3NYkIl/.DCWLu',0),(6,3,6,'$2a$12$0CGEyxH4eGB6hffSPQ5Pv.k.BLpL7VIbZ0P.YgIj3NYkIl/.DCWLu',0),(7,4,7,'1456',0),(8,4,8,'$2a$12$0CGEyxH4eGB6hffSPQ5Pv.k.BLpL7VIbZ0P.YgIj3NYkIl/.DCWLu',0),(9,5,9,'$2a$12$0CGEyxH4eGB6hffSPQ5Pv.k.BLpL7VIbZ0P.YgIj3NYkIl/.DCWLu',0),(10,5,10,'$2a$12$0CGEyxH4eGB6hffSPQ5Pv.k.BLpL7VIbZ0P.YgIj3NYkIl/.DCWLu',0);
/*!40000 ALTER TABLE `card` ENABLE KEYS */;
UNLOCK TABLES;
--
-- Table structure for table `card_type`
--

DROP TABLE IF EXISTS `card_type`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `card_type` (
  `id` int NOT NULL AUTO_INCREMENT,
  `type` varchar(25) NOT NULL,
  PRIMARY KEY (`id`),
  UNIQUE KEY `type_UNIQUE` (`type`)
) ENGINE=InnoDB AUTO_INCREMENT=5 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `card_type`
--

LOCK TABLES `card_type` WRITE;
/*!40000 ALTER TABLE `card_type` DISABLE KEYS */;
INSERT INTO `card_type` VALUES (1,'Credit'),(2,'Debit');
/*!40000 ALTER TABLE `card_type` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `client`
--

DROP TABLE IF EXISTS `client`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `client` (
  `id_client` int NOT NULL AUTO_INCREMENT,
  `fname` varchar(50) DEFAULT NULL,
  `lname` varchar(50) DEFAULT NULL,
  `addr_street` varchar(50) DEFAULT NULL,
  `addr_municipality` varchar(50) DEFAULT NULL,
  `phone_num` varchar(45) DEFAULT NULL,
  PRIMARY KEY (`id_client`)
) ENGINE=InnoDB AUTO_INCREMENT=6 DEFAULT CHARSET=utf8mb3;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `client`
--

LOCK TABLES `client` WRITE;
/*!40000 ALTER TABLE `client` DISABLE KEYS */;
INSERT INTO `client` VALUES (1,'Pekka','Roos','Patakuja 17','02770, Espoo','0500195167'),(2,'Jari','Paananen','Jalonkatu 50','90410, OULU','0460031531'),(3,'Emilia','Hissa','Aapraminkaari','01610, Vantaa','0405280975'),(4,'Hanna','Jutunen','Harjukuja 55','00760, Helsinki','0501698885'),(5,'Emmi','Nivala','Kitronintie 2','93610, Kuusamo','0442050124');
/*!40000 ALTER TABLE `client` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `transaction`
--

DROP TABLE IF EXISTS `transaction`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `transaction` (
  `id_transaction` int NOT NULL AUTO_INCREMENT,
  `id_account` int DEFAULT NULL,
  `id_card` int DEFAULT NULL,
  `transaction_date` date DEFAULT NULL,
  `transaction` varchar(45) DEFAULT NULL,
  `amount` float DEFAULT NULL,
  PRIMARY KEY (`id_transaction`),
  KEY `account_transaction_idx` (`id_account`),
  KEY `card_transaction_idx` (`id_card`),
  CONSTRAINT `account_transaction` FOREIGN KEY (`id_account`) REFERENCES `account` (`id_account`) ON DELETE RESTRICT ON UPDATE CASCADE,
  CONSTRAINT `card_transaction` FOREIGN KEY (`id_card`) REFERENCES `card` (`id_card`) ON DELETE RESTRICT ON UPDATE CASCADE
) ENGINE=InnoDB AUTO_INCREMENT=116 DEFAULT CHARSET=utf8mb3;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `transaction`
--

LOCK TABLES `transaction` WRITE;
/*!40000 ALTER TABLE `transaction` DISABLE KEYS */;
INSERT INTO `transaction` VALUES (1,9,10,'2015-01-10','Transfer',-250),(2,6,5,'2015-02-03','Deposit',230),(3,10,9,'2015-04-08','Transfer',-20),(4,7,8,'2015-05-13','Received',270),(5,10,9,'2015-7-22','Transfer',-440),(6,2,2,'2016-01-23','Deposit',500),(7,5,6,'2016-02-14','Transfer',-30),(8,2,2,'2016-03-08','Deposit',300),(9,1,2,'2016-04-16','Transfer',-30),(10,4,5,'2016-04-26','Transfer',-100),(11,3,4,'2016-06-13','Received',40),(12,8,8,'2016-08-04','Withdraw',-60),(13,6,6,'2016-09-20','Deposit',160),(14,2,6,'2016-10-22','Received',350),(15,4,4,'2016-11-04','Deposit',100),(16,8,8,'2016-11-30','Withdraw',-60),(17,4,7,'2016-12-05','Received',80),(18,4,4,'2017-03-13','Deposit',400),(19,1,6,'2017-04-02','Transfer',-200),(20,6,6,'2017-05-01','Withdraw',-450),(21,5,5,'2017-10-10','Deposit',300),(22,3,3,'2017-11-02','Withdraw',-290),(23,6,6,'2017-11-07','Deosit',30),(24,7,7,'2017-11-16','Transfer',-83),(25,6,9,'2018-06-17','Transfer',-240),(26,10,10,'2018-06-25','Deposit',150),(27,3,3,'2018-07-06','Withdraw',-120),(28,8,8,'2018-10-12','Deposit',-130),(29,6,6,'2018-11-04','Deposit',190),(30,3,10,'2018-11-09','Transfer',-160),(31,4,5,'2018-12-03','Withdraw',-360),(32,6,9,'2018-12-15','Received',380),(33,4,7,'2019-02-05','Transfer',-180),(34,10,6,'2019-05-24','Received',330),(35,10,6,'2019-06-29','Transfer',-250),(36,6,9,'2019-07-19','Transfer',-410),(37,5,4,'2019-08-04','Transfer',-430),(38,3,3,'2019-10-23','Deposit',280),(39,5,4,'2020-01-19','Withdraw',-200),(40,6,9,'2020-01-31','Received',20),(41,1,1,'2020-04-27','Withdraw',-210),(42,5,4,'2020-05-16','Received',120),(43,9,8,'2020-05-30','Transfer',-400),(44,9,8,'2020-07-01','Deposit',100),(45,4,7,'2020-07-05','Withdraw',-20),(46,8,10,'2020-09-26','Transfer',-360),(47,6,9,'2020-09-28','Deposit',20),(48,2,5,'2021-04-25','Withdraw',-150),(49,5,4,'2021-08-10','Transfer',-300),(50,8,10,'2021-10-17','Withdraw',-400),(51,10,6,'2021-11-27','Withdraw',-490),(52,6,9,'2021-12-06','Received',-310),(53,1,1,'2021-04-05','Deposit',230),(54,1,1,'2021-04-25','Transfer',-68),(55,1,1,'2021-06-10','Deposit',450),(56,10,6,'2021-07-20','Withdraw',500),(57,8,10,'2021-09-22','Deposit',500),(58,5,4,'2021-01-30','Transfer',-220),(59,8,10,'2021-02-03','Received',430),(60,9,8,'2021-04-08','Transfer',-100),(61,7,2,'2021-05-01','Withdraw',-200),(62,3,3,'2021-10-25','Transfer',-250),(63,10,6,'2022-01-05','Deposit',-100),(64,3,3,'2022-01-10','Withdraw',-40),(65,2,2,'2022-01-19','Deposit',30),(66,1,1,'2022-04-28','Deposit',40),(67,5,4,'2022-11-20','Received',30),(68,1,5,'2022-12-04','Transfer',-50),(69,2,5,'2022-12-04','Received',50),(70,2,4,'2022-12-04','Received',50);
/*!40000 ALTER TABLE `transaction` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Dumping routines for database 'group_16'
--
/*!50003 DROP PROCEDURE IF EXISTS `debit_transfer` */;
/*!50003 SET @saved_cs_client      = @@character_set_client */ ;
/*!50003 SET @saved_cs_results     = @@character_set_results */ ;
/*!50003 SET @saved_col_connection = @@collation_connection */ ;
/*!50003 SET character_set_client  = utf8mb4 */ ;
/*!50003 SET character_set_results = utf8mb4 */ ;
/*!50003 SET collation_connection  = utf8mb4_0900_ai_ci */ ;
/*!50003 SET @saved_sql_mode       = @@sql_mode */ ;
/*!50003 SET sql_mode              = 'ONLY_FULL_GROUP_BY,STRICT_TRANS_TABLES,NO_ZERO_IN_DATE,NO_ZERO_DATE,ERROR_FOR_DIVISION_BY_ZERO,NO_ENGINE_SUBSTITUTION' */ ;
DELIMITER ;;
CREATE DEFINER=`root`@`localhost` PROCEDURE `debit_transfer`(IN account_id1 INT, IN account_id2 INT, IN amount DOUBLE )
BEGIN
  DECLARE test1, test2, id_card1, id_card2 INT DEFAULT 0;
  START TRANSACTION;
  UPDATE account SET balance=balance-amount WHERE id_account=account_id1 AND balance>=amount;
  SET test1=ROW_COUNT();
  UPDATE account SET balance=balance+amount WHERE id_account=account_id2;
  SET test2=ROW_COUNT();
    IF (test1 > 0 AND test2 >0) THEN COMMIT;
        set id_card1=(select card.id_card from card where card.id_account=account_id1);
        set id_card2=(select card.id_card from card where card.id_account=account_id2);
        INSERT INTO transaction(transaction.id_account, transaction.id_card, transaction.transaction, transaction.transaction_date, transaction.amount) VALUES(account_id1, id_card1,'Tilisiirto', date_format(NOW(), "%Y-%m-%d"), amount*-1);
        INSERT INTO transaction(transaction.id_account, transaction.id_card, transaction.transaction, transaction.transaction_date, transaction.amount) VALUES(account_id2, id_card2,'Vastaanotto',date_format(NOW(), "%Y-%m-%d"), amount);
    ELSE
      ROLLBACK;
  END IF;
END ;;
DELIMITER ;
/*!50003 SET sql_mode              = @saved_sql_mode */ ;
/*!50003 SET character_set_client  = @saved_cs_client */ ;
/*!50003 SET character_set_results = @saved_cs_results */ ;
/*!50003 SET collation_connection  = @saved_col_connection */ ;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2022-12-06 17:28:26
