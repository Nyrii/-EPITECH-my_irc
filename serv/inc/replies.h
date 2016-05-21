/*
** replies.h for replies in /Users/noboud_n/Documents/Share/PSU_2015_myirc/serv/inc/
**
** Made by Nyrandone Noboud-Inpeng
** Login   <noboud_n@epitech.eu>
**
** Started on  Thu May 19 16:08:38 2016 Nyrandone Noboud-Inpeng
** Last update Sat May 21 22:51:37 2016 Nyrandone Noboud-Inpeng
*/

#ifndef REPLIES_H_
# define REPLIES_H_

# define ERR_UNKNOWNCOMMAND "421 %s %s :Unknown command\r\n"
# define ERR_NEEDMOREPARAMS "461 %s %s :Not enough parameters\r\n"
# define ERR_NOSUCHSERVER(X, Y) "402 "X" "Y" :No such server\r\n"
# define ERR_NICKNAMEINUSE "433 %s :Nickname is already in use\r\n"
# define ERR_ERRONEUSNICKNAME "432 %s :Erroneus nickname\r\n"
# define ERR_NOSUCHNICK "401 %s :No such nick/channel\r\n"
# define ERR_NONICKNAMEGIVEN "431 :No nickname given\r\n"
# define ERR_NOSUCHCHANNEL "403 %s :No such channel\r\n"
# define ERR_USERONCHANNEL "443 %s %s :is already on channel\r\n"
# define ERR_NOTONCHANNEL "442 %s :You're not on that channel\r\n"
# define ERR_NOTEXTTOSEND "412 :No text to send\r\n"
# define ERR_CANNOTSENDTOCHAN "404 %s :Cannot send to channel\r\n"
# define RPL_NICKOK "NICK %s\r\n"
# define RPL_JOINOK ":%s JOIN :%s\r\n"
# define RPL_PARTOK ":%s PART :%s\r\n"
# define RPL_MSG "MSG "
# define RPL_PRIVMSG "PRIVMSG "
# define RPL_LISTSTART "321 Channel : Users Name\r\n"
# define RPL_LIST "322 "
# define RPL_LISTEND "323 :End of channel list\r\n"
# define RPL_USERSTART "392 :UserID Terminal Host\r\n"
# define RPL_USERS(X, Y, Z) "393 : "X" "Y" "Z"\r\n"
# define RPL_NOUSERS "395 :Nobody logged in\r\n"
# define RPL_ENDOFUSERS "394 :End of users\r\n"
# define RPL_TOPIC(X, Y) "332 "X" :"Y"\r\n"
# define RPL_NAMREPLAY "353 %s :%s\r\n"
# define RPL_ENDOFNAMES "366 %s :End of /NAMES list\r\n"

#endif /* !REPLIES_H_ */
