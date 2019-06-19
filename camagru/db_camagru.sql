-- phpMyAdmin SQL Dump
-- version 4.8.5
-- https://www.phpmyadmin.net/
--
-- Host: localhost:3306
-- Generation Time: Jun 19, 2019 at 08:01 AM
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
-- Table structure for table `cadres`
--

CREATE TABLE `cadres` (
  `id` int(11) NOT NULL,
  `link_cadre` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Table structure for table `comment`
--

CREATE TABLE `comment` (
  `id` int(11) NOT NULL,
  `id_user` int(11) NOT NULL,
  `id_img` int(11) NOT NULL,
  `id_user_img` int(11) NOT NULL,
  `commentary` text NOT NULL
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
  `comments_img` int(11) NOT NULL,
  `img_date` date NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Dumping data for table `images`
--

INSERT INTO `images` (`id_img`, `link_img`, `id_user_img`, `likes_img`, `comments_img`, `img_date`) VALUES
(1, 'images/21_20190618022732.png', 21, 0, 0, '2019-06-18'),
(2, 'images/24_20190618023222.png', 24, 0, 0, '2019-06-18'),
(3, 'images/24_20190618023342.png', 24, 0, 0, '2019-06-18'),
(4, 'images/26_20190618054933.png', 26, 0, 0, '2019-06-18'),
(5, 'images/26_20190618063651.png', 26, 0, 0, '2019-06-18'),
(6, 'images/26_20190618063851.png', 26, 0, 0, '2019-06-18'),
(7, 'images/26_20190618063913.png', 26, 0, 0, '2019-06-18'),
(8, 'images/26_20190618063920.png', 26, 0, 0, '2019-06-18'),
(9, 'images/26_20190618063931.png', 26, 0, 0, '2019-06-18'),
(10, 'images/26_20190618070950.png', 26, 0, 0, '2019-06-18'),
(11, 'images/26_20190618070956.png', 26, 0, 0, '2019-06-18'),
(12, 'images/26_20190618071208.png', 26, 0, 0, '2019-06-18'),
(13, 'images/26_20190618074317.png', 26, 0, 0, '2019-06-18'),
(14, 'images/26_20190618081855.png', 26, 0, 0, '2019-06-18'),
(15, 'images/26_20190618082034.png', 26, 0, 0, '2019-06-18'),
(16, 'images/26_20190618082046.png', 26, 0, 0, '2019-06-18'),
(17, 'images/26_20190618083121.png', 26, 0, 0, '2019-06-18'),
(18, 'images/26_20190618083137.png', 26, 0, 0, '2019-06-18'),
(19, 'images/26_20190618083300.png', 26, 0, 0, '2019-06-18'),
(20, 'images/21_20190619024311.png', 21, 0, 0, '2019-06-19'),
(21, 'images/21_20190619024613.png', 21, 0, 0, '2019-06-19'),
(22, 'images/21_20190619030227.png', 21, 0, 0, '2019-06-19'),
(23, 'images/21_20190619053750.png', 21, 0, 0, '2019-06-19'),
(24, 'images/21_20190619060028.png', 21, 0, 0, '2019-06-19'),
(25, 'images/24_20190619070548.png', 24, 0, 0, '2019-06-19');

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
(9, 'yo@yo.com', 'yo', '40bd001563085fc35165329ea1ff5c5ecbdbbeef', '', 1),
(15, 'ced@ced.gf', 'ced', '40bd001563085fc35165329ea1ff5c5ecbdbbeef', '87562814297', 1),
(17, 'aa@aa.fr', 'aaa', '7e240de74fb1ed08fa08d38063f6a6a91462a815', '61185675220', 1),
(21, 'matt.scopioni@gmail.com', '123', '40bd001563085fc35165329ea1ff5c5ecbdbbeef', '11358074591', 1),
(24, 'scorpioni.matt@gmail.com', 'matt', '6ad196bef982c2a755ffad982690f61aa4b93b26', '64969630264', 1),
(26, '42betatest@gmail.com', 'beta', '6ad196bef982c2a755ffad982690f61aa4b93b26', '98969322427', 1);

--
-- Indexes for dumped tables
--

--
-- Indexes for table `cadres`
--
ALTER TABLE `cadres`
  ADD PRIMARY KEY (`id`);

--
-- Indexes for table `comment`
--
ALTER TABLE `comment`
  ADD PRIMARY KEY (`id`);

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
-- AUTO_INCREMENT for table `cadres`
--
ALTER TABLE `cadres`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT;

--
-- AUTO_INCREMENT for table `comment`
--
ALTER TABLE `comment`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT;

--
-- AUTO_INCREMENT for table `images`
--
ALTER TABLE `images`
  MODIFY `id_img` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=26;

--
-- AUTO_INCREMENT for table `users`
--
ALTER TABLE `users`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=27;

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
