CREATE DATABASE  IF NOT EXISTS `wb` /*!40100 DEFAULT CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci */ /*!80016 DEFAULT ENCRYPTION='N' */;
USE `wb`;
-- MySQL dump 10.13  Distrib 8.0.18, for Win64 (x86_64)
--
-- Host: 34.41.117.214    Database: wb
-- ------------------------------------------------------
-- Server version	8.0.34

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
-- Table structure for table `employee_attendance`
--

DROP TABLE IF EXISTS `employee_attendance`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `employee_attendance` (
  `real_name` varchar(20) NOT NULL COMMENT '真实姓名',
  `d1th` int DEFAULT '0',
  `d2th` int DEFAULT '0',
  `d3th` int DEFAULT '0',
  `d4th` int DEFAULT '0',
  `d5th` int DEFAULT '0',
  `d6th` int DEFAULT '0',
  `d7th` int DEFAULT '0',
  `d8th` int DEFAULT '0',
  `d9th` int DEFAULT '0',
  `d10th` int DEFAULT '0',
  `d11th` int DEFAULT '0',
  `d12th` int DEFAULT '0',
  `d13th` int DEFAULT '0',
  `d14th` int DEFAULT '0',
  `d15th` int DEFAULT '0',
  `d16th` int DEFAULT '0',
  `d17th` int DEFAULT '0',
  `d18th` int DEFAULT '0',
  `d19th` int DEFAULT '0',
  `d20th` int DEFAULT '0',
  `d21th` int DEFAULT '0',
  `d22th` int DEFAULT '0',
  `d23th` int DEFAULT '0',
  `d24th` int DEFAULT '0',
  `d25th` int DEFAULT '0',
  `d26th` int DEFAULT '0',
  `d27th` int DEFAULT '0',
  `d28th` int DEFAULT '0',
  `d29th` int DEFAULT '0',
  `d30th` int DEFAULT '0',
  `d31th` int DEFAULT '0',
  `created_time` datetime DEFAULT NULL COMMENT '记录创建时间',
  KEY `real_name` (`real_name`),
  CONSTRAINT `employee_attendance_ibfk_1` FOREIGN KEY (`real_name`) REFERENCES `employee_info` (`real_name`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `employee_attendance`
--

LOCK TABLES `employee_attendance` WRITE;
/*!40000 ALTER TABLE `employee_attendance` DISABLE KEYS */;
INSERT INTO `employee_attendance` VALUES ('楼远志',0,0,0,0,0,0,0,0,0,0,0,0,8,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,NULL),('张三',0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,NULL),('李四',0,0,0,0,0,0,0,0,0,0,0,0,8,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,NULL),('王五',0,0,0,0,0,0,0,0,0,0,0,0,6,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,NULL),('赵六',0,0,0,0,0,0,0,0,0,0,0,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,NULL);
/*!40000 ALTER TABLE `employee_attendance` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `employee_info`
--

DROP TABLE IF EXISTS `employee_info`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `employee_info` (
  `work_card` varchar(10) DEFAULT NULL COMMENT '工号牌',
  `real_name` varchar(20) NOT NULL COMMENT '真实姓名',
  `sex` varchar(5) DEFAULT NULL COMMENT '性别',
  `position` varchar(20) DEFAULT NULL COMMENT '职务',
  `xm` varchar(20) DEFAULT NULL COMMENT '项目',
  `bm` varchar(20) DEFAULT NULL COMMENT '部门',
  `entry_time` date DEFAULT NULL COMMENT '入职时间',
  `id_card` varchar(20) DEFAULT NULL COMMENT '身份证',
  `hometown` varchar(50) DEFAULT NULL COMMENT '籍贯',
  `nation` varchar(10) DEFAULT NULL COMMENT '民族',
  `phone_num` varchar(20) DEFAULT NULL COMMENT '电话',
  `emergency_phone_num` varchar(20) DEFAULT NULL COMMENT '应急电话',
  `address` varchar(50) DEFAULT NULL COMMENT '住址',
  `degree` varchar(20) DEFAULT NULL COMMENT '学历',
  `major` varchar(20) DEFAULT NULL COMMENT '专业',
  `certificate` varchar(40) DEFAULT NULL COMMENT '证书',
  `job_title` varchar(20) DEFAULT NULL COMMENT '职称',
  `speciality` varchar(30) DEFAULT NULL COMMENT '特长',
  `state_of_health` varchar(30) DEFAULT NULL COMMENT '健康状况',
  `marriage` varchar(5) DEFAULT NULL COMMENT '婚姻状况',
  `political_status` varchar(10) DEFAULT NULL COMMENT '政治面貌',
  `social_security` varchar(10) DEFAULT NULL COMMENT '社保',
  `indstrl_injry_insrnce` varchar(10) DEFAULT NULL COMMENT '工伤险',
  `accident_insrnce` varchar(10) DEFAULT NULL COMMENT '意外险',
  `basic_wage` decimal(10,0) DEFAULT NULL COMMENT '基本工资',
  `overtime_wage` decimal(10,0) DEFAULT NULL COMMENT '超时工资',
  `appraisal_wage` decimal(10,0) DEFAULT NULL COMMENT '考核工资',
  `job_wage` decimal(10,0) DEFAULT NULL COMMENT '岗位工资',
  `scl_scurty_subsidy` decimal(10,0) DEFAULT NULL COMMENT '社保补贴',
  `accommodation_allowance` decimal(10,0) DEFAULT NULL COMMENT '食宿补贴',
  `contract` varchar(30) DEFAULT NULL COMMENT '合同',
  `change_date` date DEFAULT NULL COMMENT '调动时间',
  `leave_date` date DEFAULT NULL COMMENT '离职时间',
  `change_reason` varchar(200) DEFAULT NULL COMMENT '调动原因',
  `leave_reason` varchar(200) DEFAULT NULL COMMENT '离职原因',
  `leave_settlement` varchar(50) DEFAULT NULL COMMENT '离职结算',
  `in_service` varchar(5) DEFAULT NULL COMMENT '在职',
  `birthday` date DEFAULT NULL COMMENT '生日',
  `bank_card_num` varchar(30) DEFAULT NULL COMMENT '银行卡号',
  `remark` varchar(200) DEFAULT NULL COMMENT '备注',
  `created_time` datetime DEFAULT NULL COMMENT '记录创建时间',
  PRIMARY KEY (`real_name`),
  KEY `index_xm_bm` (`xm`,`bm`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `employee_info`
--

LOCK TABLES `employee_info` WRITE;
/*!40000 ALTER TABLE `employee_info` DISABLE KEYS */;
INSERT INTO `employee_info` VALUES ('0002','张三','男','','文鼎公寓','行政部','2024-04-13','111111195010291111','义乌','汉族','11111111111','11111111111','','硕士','计算机','','','计算机','健康','未婚','群众',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,'',NULL,NULL,NULL,NULL,NULL,NULL,'1950-10-29',NULL,NULL,NULL),('0003','李四','女','','文鼎公寓','行政部','2024-04-13','111111198010291111','义乌','汉族','11111111111','11111111111','','硕士','计算机','','','计算机','健康','未婚','群众',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,'',NULL,NULL,NULL,NULL,NULL,NULL,'1980-10-29',NULL,NULL,NULL),('0001','楼远志','男','总经理','公司总部','项目经理','2024-04-13','111111200010291111','义乌','汉族','11111111111','11111111111','','硕士','计算机','','','计算机','健康','未婚','群众',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,'',NULL,NULL,NULL,NULL,NULL,NULL,'2000-10-29',NULL,NULL,NULL),('0004','王五','男','','文鼎公寓','行政部','2024-04-13','111111199010291111','义乌','汉族','11111111111','11111111111','','硕士','计算机','','','计算机','健康','未婚','群众',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,'',NULL,NULL,NULL,NULL,NULL,NULL,'1990-10-29',NULL,NULL,NULL),('0005','赵六','男','','文鼎公寓','客服部','2024-04-13','111111199510291111','义乌','汉族','11111111111','11111111111','','硕士','计算机','','','计算机','健康','未婚','群众',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,'',NULL,NULL,NULL,NULL,NULL,NULL,'1995-10-29',NULL,NULL,NULL);
/*!40000 ALTER TABLE `employee_info` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `employee_schedule`
--

DROP TABLE IF EXISTS `employee_schedule`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `employee_schedule` (
  `real_name` varchar(20) NOT NULL COMMENT '真实姓名',
  `d1th` int DEFAULT '2',
  `d2th` int DEFAULT '2',
  `d3th` int DEFAULT '2',
  `d4th` int DEFAULT '2',
  `d5th` int DEFAULT '2',
  `d6th` int DEFAULT '2',
  `d7th` int DEFAULT '2',
  `d8th` int DEFAULT '2',
  `d9th` int DEFAULT '2',
  `d10th` int DEFAULT '2',
  `d11th` int DEFAULT '2',
  `d12th` int DEFAULT '2',
  `d13th` int DEFAULT '2',
  `d14th` int DEFAULT '2',
  `d15th` int DEFAULT '2',
  `d16th` int DEFAULT '2',
  `d17th` int DEFAULT '2',
  `d18th` int DEFAULT '2',
  `d19th` int DEFAULT '2',
  `d20th` int DEFAULT '2',
  `d21th` int DEFAULT '2',
  `d22th` int DEFAULT '2',
  `d23th` int DEFAULT '2',
  `d24th` int DEFAULT '2',
  `d25th` int DEFAULT '2',
  `d26th` int DEFAULT '2',
  `d27th` int DEFAULT '2',
  `d28th` int DEFAULT '2',
  `d29th` int DEFAULT '2',
  `d30th` int DEFAULT '2',
  `d31th` int DEFAULT '2',
  `created_time` datetime DEFAULT NULL COMMENT '记录创建时间',
  KEY `real_name` (`real_name`),
  CONSTRAINT `employee_schedule_ibfk_1` FOREIGN KEY (`real_name`) REFERENCES `employee_info` (`real_name`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `employee_schedule`
--

LOCK TABLES `employee_schedule` WRITE;
/*!40000 ALTER TABLE `employee_schedule` DISABLE KEYS */;
INSERT INTO `employee_schedule` VALUES ('楼远志',2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,NULL),('张三',2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,NULL),('李四',2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,0,2,2,2,2,2,2,2,2,2,2,2,2,2,2,NULL),('王五',2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,NULL),('赵六',2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,NULL);
/*!40000 ALTER TABLE `employee_schedule` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `purchase`
--

DROP TABLE IF EXISTS `purchase`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `purchase` (
  `purchase_id` varchar(40) NOT NULL COMMENT '采购单号',
  `serial_number` int DEFAULT NULL COMMENT '序号',
  `pro_date` varchar(35) DEFAULT NULL COMMENT '项目和日期',
  `app_date` date DEFAULT NULL COMMENT '日期',
  `applicant` varchar(10) DEFAULT NULL COMMENT '申请人',
  `thing_name` varchar(50) DEFAULT NULL COMMENT '物品名称',
  `number` int DEFAULT NULL COMMENT '数量',
  `unit` varchar(10) DEFAULT NULL COMMENT '单位',
  `format` varchar(30) DEFAULT NULL COMMENT '型号规格',
  `application` varchar(50) DEFAULT NULL COMMENT '用途',
  `cost` decimal(10,2) DEFAULT NULL COMMENT '金额',
  `advice` varchar(50) DEFAULT NULL COMMENT '审批意见',
  `purchase_date` varchar(35) DEFAULT NULL COMMENT '采购日期',
  `xmjl_name` varchar(10) DEFAULT NULL COMMENT '项目经理',
  `zhb_name` varchar(10) DEFAULT NULL COMMENT '综合部',
  `zjb_name` varchar(10) DEFAULT NULL COMMENT '总经办',
  `state` int DEFAULT NULL COMMENT '状态',
  `created_time` datetime DEFAULT NULL COMMENT '记录创建时间',
  PRIMARY KEY (`purchase_id`),
  KEY `index_state` (`state`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `purchase`
--

LOCK TABLES `purchase` WRITE;
/*!40000 ALTER TABLE `purchase` DISABLE KEYS */;
INSERT INTO `purchase` VALUES ('公司总部#2024-04-09#1',1,'公司总部#2024-04-09','2024-04-09','楼远志','雨伞',10,'个','长柄','挡雨',NULL,'不行',NULL,'楼远志','楼远志',NULL,7,'2024-04-13 19:41:37'),('公司总部#2024-04-09#2',2,'公司总部#2024-04-09','2024-04-09','楼远志','拖把',10,'个','长柄','拖地',NULL,'不行',NULL,'楼远志','楼远志',NULL,7,'2024-04-13 19:41:37'),('公司总部#2024-04-10#1',1,'公司总部#2024-04-10','2024-04-10','楼远志','雨伞',10,'个','长柄','挡雨',10.00,'','2024/4/13','楼远志','楼远志','楼远志',5,'2024-04-13 19:41:27'),('公司总部#2024-04-10#2',2,'公司总部#2024-04-10','2024-04-10','楼远志','拖把',10,'个','长柄','拖地',20.00,'','2024/4/13','楼远志','楼远志','楼远志',5,'2024-04-13 19:41:27'),('公司总部#2024-04-11#1',1,'公司总部#2024-04-11','2024-04-11','楼远志','雨伞',10,'个','长柄','挡雨',NULL,'',NULL,'楼远志',NULL,NULL,2,'2024-04-13 19:41:16'),('公司总部#2024-04-11#2',2,'公司总部#2024-04-11','2024-04-11','楼远志','拖把',10,'个','长柄','拖地',NULL,'',NULL,'楼远志',NULL,NULL,2,'2024-04-13 19:41:16'),('公司总部#2024-04-12#1',1,'公司总部#2024-04-12','2024-04-12','楼远志','雨伞',10,'个','长柄','挡雨',NULL,'',NULL,'楼远志','楼远志',NULL,3,'2024-04-13 19:41:00'),('公司总部#2024-04-12#2',2,'公司总部#2024-04-12','2024-04-12','楼远志','拖把',10,'个','长柄','拖地',NULL,'',NULL,'楼远志','楼远志',NULL,3,'2024-04-13 19:41:00'),('公司总部#2024-04-13#1',1,'公司总部#2024-04-13','2024-04-13','楼远志','雨伞',10,'个','长柄','挡雨',NULL,NULL,NULL,NULL,NULL,NULL,1,'2024-04-13 19:44:12'),('公司总部#2024-04-13#2',2,'公司总部#2024-04-13','2024-04-13','楼远志','拖把',10,'个','长柄','拖地',NULL,NULL,NULL,NULL,NULL,NULL,1,'2024-04-13 19:44:12');
/*!40000 ALTER TABLE `purchase` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `user_info`
--

DROP TABLE IF EXISTS `user_info`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `user_info` (
  `id` int NOT NULL AUTO_INCREMENT COMMENT 'ID',
  `user_name` varchar(30) DEFAULT NULL COMMENT '用户名',
  `user_real_name` varchar(20) DEFAULT NULL COMMENT '真实姓名',
  `user_password` varchar(20) DEFAULT NULL COMMENT '密码',
  `user_encrypted_password` varchar(50) DEFAULT NULL COMMENT '加密后密码',
  `xm` varchar(20) DEFAULT NULL COMMENT '项目',
  `bm` varchar(20) DEFAULT NULL COMMENT '部门',
  `work_card` varchar(10) DEFAULT NULL COMMENT '工号牌',
  `permission` int DEFAULT NULL COMMENT '权限',
  `created_time` datetime DEFAULT NULL COMMENT '记录创建时间',
  PRIMARY KEY (`id`),
  KEY `index_NmPwdCrd` (`user_name`,`user_encrypted_password`,`work_card`)
) ENGINE=InnoDB AUTO_INCREMENT=2 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `user_info`
--

LOCK TABLES `user_info` WRITE;
/*!40000 ALTER TABLE `user_info` DISABLE KEYS */;
INSERT INTO `user_info` VALUES (1,'楼远志','楼远志','1','c4ca4238a0b923820dcc509a6f75849b','公司总部','项目经理','0001',NULL,'2024-04-13 19:07:57');
/*!40000 ALTER TABLE `user_info` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2024-04-13 15:48:44
