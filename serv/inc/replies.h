/*
** replies.h for replies in /Users/noboud_n/Documents/Share/PSU_2015_myirc/serv/inc/
**
** Made by Nyrandone Noboud-Inpeng
** Login   <noboud_n@epitech.eu>
**
** Started on  Thu May 19 16:08:38 2016 Nyrandone Noboud-Inpeng
** Last update Sat May 21 13:56:45 2016 Nyrandone Noboud-Inpeng
*/

#ifndef REPLIES_H_
# define REPLIES_H_

# define ERR_UNKNOWNCOMMAND "421 %s %s :Unknown command\r\n"
# define ERR_NEEDMOREPARAMS "461 %s %s :Not enough parameters\r\n"
# define ERR_NOSUCHSERVER(X, Y) "402 "X" "Y" :No such server\r\n"
# define ERR_NICKNAMEUSE(X, Y) "433 "X" "Y" :Nickname is already in use\r\n"
# define ERR_ERRONEUSNICKNAME(X, Y) "432 "X" "Y" :Erroneus nickname\r\n"
# define ERR_NOSUCHNICK "401 %s :No such nick/channel\r\n"
# define ERR_NONICKNAMEGIVEN "431 :No nickname given\r\n"
# define ERR_NOSUCHCHANNEL "403 %s :No such channel\r\n"
# define ERR_USERONCHANNEL "443 %s %s :is already on channel\r\n"
# define ERR_NOTONCHANNEL "442 %s :You're not on that channel\r\n"
# define RPL_NICKOK(X, Y) X"NICK "Y"\r\n"
# define RPL_JOINOK ":%s JOIN :%s\r\n"
# define RPL_PARTOK ":%s PART :%s\r\n"
# define RPL_LISTSTART(X) "321 Channel : Users Name\r\n"
# define RPL_LIST(X, Y, Z) "322 "X" "Y" :"Z"\r\n"
# define RPL_LISTEND "323 :End of /LIST\r\n"
# define RPL_USERSTART "392 :UserID Terminal Host\r\n"
# define RPL_USERS(X, Y, Z) "393 : "X" "Y" "Z"\r\n"
# define RPL_NOUSERS "395 :Nobody logged in\r\n"
# define RPL_ENDOFUSERS "394 :End of users\r\n"
# define RPL_TOPIC(X, Y) "332 "X" :"Y"\r\n"
# define RPL_NAMREPLAY "353 %s :%s\r\n"
# define RPL_ENDOFNAMES "366 %s :End of /NAMES list\r\n"
# define RPL_SENDPRIVMSG(X, Y) "PRIVMSG "X" :"Y"\r\n"
# define RPL_SENDMSG(X, Y) "MSG "X" :"Y"\r\n"

#endif /* !REPLIES_H_ */
