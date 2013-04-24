SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0;
SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0;
SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='TRADITIONAL';

CREATE SCHEMA IF NOT EXISTS `REGDB` ;
USE `REGDB`;

-- -----------------------------------------------------
-- Table `REGDB`.`EXPSWITCH_TEST`
-- -----------------------------------------------------
DROP TABLE IF EXISTS `REGDB`.`EXPSWITCH_TEST` ;

CREATE  TABLE IF NOT EXISTS `REGDB`.`EXPSWITCH_TEST` (
  `id` INT NOT NULL AUTO_INCREMENT ,
  `exper_id` INT NOT NULL ,
  `station`  INT UNSIGNED NOT NULL ,
  `switch_time` BIGINT UNSIGNED NOT NULL ,
  `requestor_uid` VARCHAR(32) NOT NULL ,
  PRIMARY KEY (`id`) ,
  INDEX `EXPSWITCH_TEST_FK_1` (`exper_id` ASC) ,
  CONSTRAINT `EXPSWITCH_TEST_FK_1`
    FOREIGN KEY (`exper_id` )
    REFERENCES `REGDB`.`EXPERIMENT` (`id` )
    ON DELETE CASCADE
    ON UPDATE CASCADE)
ENGINE = InnoDB;

-- -----------------------------------------------------
-- Table `REGDB`.`EXPSWITCH_TEST_NOTIFY`
-- -----------------------------------------------------
DROP TABLE IF EXISTS `REGDB`.`EXPSWITCH_TEST_NOTIFY` ;

CREATE  TABLE IF NOT EXISTS `REGDB`.`EXPSWITCH_TEST_NOTIFY` (
  `switch_id` INT NOT NULL ,
  `uid` VARCHAR(32) NOT NULL ,
  `full_name` VARCHAR(255) NOT NULL ,
  `email` VARCHAR(255) NOT NULL ,
  `rank` ENUM('PI','INSTR_SCIENTIST','ADMIN','OTHER') NOT NULL ,
  `notified` ENUM('YES','NO') NOT NULL ,
  INDEX `EXPSWITCH_TEST_NOTIFY_FK_1` (`switch_id` ASC) ,
  CONSTRAINT `EXPSWITCH_TEST_NOTIFY_FK_1`
    FOREIGN KEY (`switch_id` )
    REFERENCES `REGDB`.`EXPSWITCH_TEST` (`id` )
    ON DELETE CASCADE
    ON UPDATE CASCADE)
ENGINE = InnoDB;

SET SQL_MODE=@OLD_SQL_MODE;
SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS;
SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS;