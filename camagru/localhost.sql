-- phpMyAdmin SQL Dump
-- version 4.8.5
-- https://www.phpmyadmin.net/
--
-- Host: localhost:3306
-- Generation Time: Jun 04, 2019 at 05:26 AM
-- Server version: 5.6.43
-- PHP Version: 5.6.40

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET AUTOCOMMIT = 0;
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Database: `db_camagru`
--
CREATE DATABASE IF NOT EXISTS `db_camagru` DEFAULT CHARACTER SET utf8 COLLATE utf8_general_ci;
USE `db_camagru`;

-- --------------------------------------------------------

--
-- Table structure for table `img`
--

CREATE TABLE `img` (
  `id_img` int(11) NOT NULL,
  `id_user` int(11) NOT NULL,
  `img` longblob NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Table structure for table `users`
--

CREATE TABLE `users` (
  `id` int(11) NOT NULL,
  `mail` varchar(255) NOT NULL,
  `pseudo` varchar(255) NOT NULL,
  `mdp` varchar(255) NOT NULL,
  `confirmkey` varchar(255) NOT NULL,
  `confirm` int(1) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Dumping data for table `users`
--

INSERT INTO `users` (`id`, `mail`, `pseudo`, `mdp`, `confirmkey`, `confirm`) VALUES
(2, 'matt@mail.com', 'mattt', '7c4a8d09ca3762af61e59520943dc26494f8941b', '', 0),
(3, 'test@test.fr', 'test', '7c4a8d09ca3762af61e59520943dc26494f8941b', '', 0),
(4, 'ceaudouy@student.42.fr', 'ceaudouy', 'b1b3773a05c0ed0176787a4f1574ff0075f7521e', '', 0),
(5, 'ceaudouy@studnt.42.fr', 'ceaudouy', '7c4a8d09ca3762af61e59520943dc26494f8941b', '', 0),
(6, 'lol@lol.fr', 'lol', 'e54ca0f451fa67adfdc259e3a21a86b1a9f5dc67', '', 0),
(7, 'matt@mail2.com', 'matt22', '7c4a8d09ca3762af61e59520943dc26494f8941b', '', 0),
(8, 'matt@mail22.com', 'matt2', '7c4a8d09ca3762af61e59520943dc26494f8941b', '', 0),
(9, 'yo@yo.com', 'yo', '40bd001563085fc35165329ea1ff5c5ecbdbbeef', '', 0),
(14, 'matt.scorpini@gmail.com', 'test111', 'a94a8fe5ccb19ba61c4c0873d391e987982fbbd3', '47902031381', 1),
(15, 'ced@ced.gf', 'ced', '40bd001563085fc35165329ea1ff5c5ecbdbbeef', '87562814297', 1),
(16, 'matt.scorpioni@gmail.com', 'mattmatt', '7c4a8d09ca3762af61e59520943dc26494f8941b', '21976902900', 0);

--
-- Indexes for dumped tables
--

--
-- Indexes for table `img`
--
ALTER TABLE `img`
  ADD PRIMARY KEY (`id_img`);

--
-- Indexes for table `users`
--
ALTER TABLE `users`
  ADD PRIMARY KEY (`id`);

--
-- AUTO_INCREMENT for dumped tables
--

--
-- AUTO_INCREMENT for table `img`
--
ALTER TABLE `img`
  MODIFY `id_img` int(11) NOT NULL AUTO_INCREMENT;

--
-- AUTO_INCREMENT for table `users`
--
ALTER TABLE `users`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=17;
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
