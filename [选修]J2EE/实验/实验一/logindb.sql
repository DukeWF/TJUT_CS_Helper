-- --------------------------------------------------------
-- 主机:                           127.0.0.1
-- 服务器版本:                        10.2.14-MariaDB - mariadb.org binary distribution
-- 服务器操作系统:                      Win64
-- HeidiSQL 版本:                  9.4.0.5125
-- --------------------------------------------------------

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET NAMES utf8 */;
/*!50503 SET NAMES utf8mb4 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;


-- 导出 j2ee 的数据库结构
CREATE DATABASE IF NOT EXISTS `j2ee` /*!40100 DEFAULT CHARACTER SET utf8 */;
USE `j2ee`;

-- 导出  表 j2ee.login_db 结构
CREATE TABLE IF NOT EXISTS `login_db` (
  `username` varchar(50) NOT NULL,
  `password` varchar(50) DEFAULT NULL,
  PRIMARY KEY (`username`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- 正在导出表  j2ee.login_db 的数据：~9 rows (大约)
/*!40000 ALTER TABLE `login_db` DISABLE KEYS */;
INSERT INTO `login_db` (`username`, `password`) VALUES
	('Apache', 'apache123'),
	('Bill', 'b2586'),
	('Bob', '1234'),
	('Comet', 'cees5'),
	('Duke', '4321'),
	('Jane', 'jeos89'),
	('Jerry', '321'),
	('Maria', 'MMm213'),
	('Tom', '123');
/*!40000 ALTER TABLE `login_db` ENABLE KEYS */;

/*!40101 SET SQL_MODE=IFNULL(@OLD_SQL_MODE, '') */;
/*!40014 SET FOREIGN_KEY_CHECKS=IF(@OLD_FOREIGN_KEY_CHECKS IS NULL, 1, @OLD_FOREIGN_KEY_CHECKS) */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
