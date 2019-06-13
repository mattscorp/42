-- phpMyAdmin SQL Dump
-- version 4.8.5
-- https://www.phpmyadmin.net/
--
-- Host: localhost:3306
-- Generation Time: Jun 07, 2019 at 07:15 AM
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

-- --------------------------------------------------------

--
-- Table structure for table `comment`
--

CREATE TABLE `comment` (
  `id_user` int(11) NOT NULL,
  `id_img` int(11) NOT NULL,
  `id_user_img` int(11) NOT NULL,
  `commentary` varchar(255) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Table structure for table `images`
--

CREATE TABLE `images` (
  `id_img` int(11) NOT NULL,
  `link_img` varchar(255) NOT NULL,
  `id_user_img` int(11) NOT NULL,
  `likes_img` int(11) NOT NULL,
  `comments_img` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Dumping data for table `images`
--

INSERT INTO `images` (`id_img`, `link_img`, `id_user_img`, `likes_img`, `comments_img`) VALUES
(5, 'images/21_20190607053956.jpg', 21, 0, 0),
(6, 'images/21_20190607053957.jpg', 21, 0, 0),
(7, 'images/21_20190607053959.jpg', 21, 0, 0),
(8, 'images/21_20190607053959.jpg', 21, 0, 0),
(9, 'images/21_20190607054000.jpg', 21, 0, 0),
(10, 'images/21_20190607054004.jpg', 21, 0, 0),
(11, 'images/21_20190607054432.jpg', 21, 0, 0),
(12, 'images/21_20190607054433.jpg', 21, 0, 0),
(13, 'images/21_20190607054620.jpg', 21, 0, 0),
(14, 'images/21_20190607054627.jpg', 21, 0, 0),
(15, 'images/21_20190607064202.jpg', 21, 0, 0);

-- --------------------------------------------------------

--
-- Table structure for table `likes`
--

CREATE TABLE `likes` (
  `id_user` int(11) NOT NULL,
  `id_img` int(11) NOT NULL,
  `likes` int(11) NOT NULL
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
(14, 'matt.scorpini@gmail.com', 'test111', '40bd001563085fc35165329ea1ff5c5ecbdbbeef', '47902031381', 1),
(15, 'ced@ced.gf', 'ced', '40bd001563085fc35165329ea1ff5c5ecbdbbeef', '87562814297', 1),
(17, 'aa@aa.fr', 'aaa', '7e240de74fb1ed08fa08d38063f6a6a91462a815', '61185675220', 1),
(21, 'matt.scopioni@gmail.com', '123', '40bd001563085fc35165329ea1ff5c5ecbdbbeef', '11358074591', 1);

--
-- Indexes for dumped tables
--

--
-- Indexes for table `images`
--
ALTER TABLE `images`
  ADD PRIMARY KEY (`id_img`),
  ADD KEY `id_user_img` (`id_user_img`);

--
-- Indexes for table `users`
--
ALTER TABLE `users`
  ADD PRIMARY KEY (`id`);

--
-- AUTO_INCREMENT for dumped tables
--

--
-- AUTO_INCREMENT for table `images`
--
ALTER TABLE `images`
  MODIFY `id_img` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=16;

--
-- AUTO_INCREMENT for table `users`
--
ALTER TABLE `users`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=22;

--
-- Constraints for dumped tables
--

--
-- Constraints for table `images`
--
ALTER TABLE `images`
  ADD CONSTRAINT `images_ibfk_1` FOREIGN KEY (`id_user_img`) REFERENCES `users` (`id`);
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
