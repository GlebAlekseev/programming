#include <iostream>
#include <string>
#include <cpp_httplib/httplib.h>
#include <vector>
#include <nlohmann/json.hpp>
#include <fstream>
#include <cmath>
#include <iomanip>
using namespace std;
using namespace httplib;
using json = nlohmann::json;
// В этой функции формируем ответ сервера на запрос


// В этой функции формируем ответ сервера на запрос
void gen_response(const Request& req, Response& res) {
    // Выводим на экран тело запроса
    //std::cout << req.body.c_str();
    //json body = req.body.c_str();

    json body = json::parse(req.body.c_str());
   /*     cout << body << endl;*/
        string str;
        if (body["request"]["original_utterance"] == json("ping") && empty(body["request"]["command"]))
        { // Периодическая проверка
            str = u8R"(
                                    {
                                      "response": {
                                        "text": "Навык работает!",
                                        "tts": "Навык работает.",
                                        "buttons": [
                                        ],
                                        "end_session": false
                                      },
                                      "version": "1.0"
                                    })";
        }
        else {
        // Рабочая область



            if (body["session"]["new"] == true)
            {//приветствие
                str = u8R"(
                                    {
                                      "response": {
                                        "text": "Здравствуйте! Я помогу вам с покупками.",
                                        "tts": "Здравствуйте! Я помогу вам с покупками.",
                                        "buttons": [
                                                        {
                                                            "title": "Помощь",
                                                            "payload": {},
                                                            "hide": true
                                                        },{
                                                            "title": "Молчать",
                                                            "payload": {},
                                                            "hide": true
                                                        }
                                        ],
                                        "end_session": false
                                      },
                                        "session_state": {
                                              "basket": [],
                                              "dtbv": true,
                                              "operating_mode": "main"

                                          },
                                      "version": "1.0"
                                    })";
            }
            else {
                //диалог


                if (empty(body["state"]["session"]))// || не валидны опред условие не валидности  (отсутствует один из параметров)
                { // алерт и завершение
                    str = u8R"(
                                    {
                                      "response": {
                                        "text": "Ошибка! Сессия не валидна.",
                                        "tts": "Ошибка! Сессия не валидна.",
                                        "buttons": [
                                        ],
                                        "end_session": true
                                      },
                                      "version": "1.0"
                                    })";
                }

                else {
                    // Working range
                    string strwait;
                    //cout << body["state"]["session"]["operating_mode"];
/*                    if (body["state"]["session"]["operating_mode"] == "main")
                    {*///Главный режим
                       strwait = u8R"(
                                    {
                                      "response": {
                                        "text": "Навык работает!",
                                        "tts": "Навык работает.",
                                        "buttons": [
                                                        {
                                                            "title": "Помощь",
                                                            "payload": {},
                                                            "hide": true
                                                        },{
                                                            "title": "Молчать",
                                                            "payload": {},
                                                            "hide": true
                                                        }
                                        ],
                                        "end_session": false
                                      },
                                        "session_state": {
                                              "basket": [],
                                              "dtbv": true,
                                              "operating_mode": "main"

                                          },
                                      "version": "1.0"
                                    })";

                       int go = 0;
                       if ((body["state"]["session"]["operating_mode"] == "help" || body["request"]["nlu"]["tokens"][0] == u8R"(помощь)") && body["request"]["nlu"]["tokens"][0] != u8R"(выход)") {
                       
                           strwait = u8R"(
                                    {
                                      "response": {
                                        "text": "Навык работает!",
                                        "tts": "Навык работает.",
                                        "buttons": [
                                                        {
                                                            "title": "Помощь",
                                                            "payload": {},
                                                            "hide": true
                                                        },{
                                                            "title": "Молчать",
                                                            "payload": {},
                                                            "hide": true
                                                        },{
                                                            "title": "Говорить",
                                                            "payload": {},
                                                            "hide": true
                                                        },{
                                                            "title": "Корзина",
                                                            "payload": {},
                                                            "hide": true
                                                        }
                                        ],
                                        "end_session": false
                                      },
                                        "session_state": {
                                              "basket": [],
                                              "dtbv": true,
                                              "operating_mode": "main"

                                          },
                                      "version": "1.0"
                                    })";
                           go = 1;
                       }

                   json j;
                   j = json::parse(strwait);
                   string price;

                   // Обработчик сохраненных данных в сессии
                   // Внос даных в сессию
                   //int szb = j["session_state"]["basket"].size();
                   //j["session_state"]["basket"][szb]["price"] = price;
                   //j["session_state"]["basket"][szb]["item"] = itemname;



                   if (!go) // условие выполнения вноса в исходник (Анти внос в help голос помощ)
                   {
                       j["session_state"]["dtbv"] = body["state"]["session"]["dtbv"];
                       j["session_state"]["basket"] = body["state"]["session"]["basket"];
                   }

                   j["session_state"]["operating_mode"] = body["state"]["session"]["operating_mode"];

                   // Подгон под сессию
                   if (!j["session_state"]["dtbv"]) // Если False меняем, тк true оставляем как на шаблоне
                   {
                       for (int i = 0; i < j["response"]["buttons"].size(); i++)
                       {
                           if (j["response"]["buttons"][i]["title"] == u8R"(Молчать)")
                           {
                               j["response"]["buttons"][i]["title"] = u8R"(Говорить)";
                           }
                       }
                   }
                 
                   if (j["session_state"]["operating_mode"] == "help") // Замена кнопки хелп в необх случае
                   {
                       for (int i = 0; i < j["response"]["buttons"].size(); i++)
                       {
                           if (j["response"]["buttons"][i]["title"] == u8R"(Помощь)")
                           {
                               j["response"]["buttons"][i]["title"] = u8R"(Выход из режима справки)";
                           }
                       }
                       //j["response"]["buttons"].push_back( json::parse(u8R"({"title": "Кратко","payload" : {},"hide" : true })"));


                   }
                   string exithelp;
                   for (int i = 0; i < body["request"]["nlu"]["tokens"].size(); i++)
                   {
                       if (i == body["request"]["nlu"]["tokens"].size() - 1)
                       {
                           exithelp += string(body["request"]["nlu"]["tokens"][i]);
                       }
                       else {
                           exithelp += string(body["request"]["nlu"]["tokens"][i]).append(" ");
                       }

                   }


                   string basketname;
                   string itemname;

                   if (body["request"]["nlu"]["tokens"].size() >= 6 && body["request"]["nlu"]["tokens"][0] == u8R"(добавить)"/*|| body["request"]["nlu"]["tokens"].size() >= 4 && body["request"]["nlu"]["tokens"] != u8R"(добавить)"*/)
                   {
                       for (int i = 0; i < body["request"]["nlu"]["tokens"].size(); i++)
                       {

                           if (i < 3)
                           {
                               if (i == 2)
                               {
                                   basketname += string(body["request"]["nlu"]["tokens"][i]);
                               }
                               else {
                                   basketname += string(body["request"]["nlu"]["tokens"][i]).append(" ");
                               }
                           }
                           else {

                               if (body["request"]["nlu"]["tokens"][body["request"]["nlu"]["tokens"].size() - 1] == u8R"(р)")
                               {
                                   price = body["request"]["nlu"]["tokens"][body["request"]["nlu"]["tokens"].size() - 2];
                               }

                               if (i < body["request"]["nlu"]["tokens"].size() - 2)
                               {
                                   
                                   if (i == body["request"]["nlu"]["tokens"].size() - 3)
                                   {
                                       itemname += string(body["request"]["nlu"]["tokens"][i]);
                                   }
                                   else {
                                       itemname += string(body["request"]["nlu"]["tokens"][i]).append(" ");
                                   }
                               }


                           }

                       }
                   }
                   if (body["request"]["nlu"]["tokens"].size() >= 4 && body["request"]["nlu"]["tokens"][0] == u8R"(удалить)")
                   {
                       for (int i = 0; i < body["request"]["nlu"]["tokens"].size(); i++)
                       {

                           if (i < 3)
                           {
                               if (i == 2)
                               {
                                   basketname += string(body["request"]["nlu"]["tokens"][i]);
                               }
                               else {
                                   basketname += string(body["request"]["nlu"]["tokens"][i]).append(" ");
                               }
                           }
                           else {


                               if (i < body["request"]["nlu"]["tokens"].size())
                               {
                                   
                                   if (i == body["request"]["nlu"]["tokens"].size() - 1)
                                   {
                                       itemname += string(body["request"]["nlu"]["tokens"][i]);
                                   }
                                   else {
                                       itemname += string(body["request"]["nlu"]["tokens"][i]).append(" ");
                                   }
                               }


                           }

                       }
                   }

                   








                  //string exithelp = string(body["request"]["nlu"]["tokens"][0]).append(" ").append(string(body["request"]["nlu"]["tokens"][1])).append(" ").append(string(body["request"]["nlu"]["tokens"][2])).append(" ").append(string(body["request"]["nlu"]["tokens"][3]));
                       // Сделать обработчик на поступающие команды
                       if (body["request"]["nlu"]["tokens"][0] == u8R"(молчать)" && go == 0)// Молчать
                       {
                           j["response"]["text"] = u8R"(Молчу, молчу)";
                           for (int i = 0; i < j["response"]["buttons"].size(); i++)
                           {
                               if (j["response"]["buttons"][i]["title"] == u8R"(Молчать)")
                               {
                                   j["response"]["buttons"][i]["title"] = u8R"(Говорить)";
                               }
                           }
                           j["session_state"]["dtbv"] = false;
                           // Ставлю сопроваждающий текст и меняю кнопку, перебрав все имеющиейся кнопки титл с необходимым заменил
                       }
                       else if (body["request"]["nlu"]["tokens"][0] == u8R"(говорить)" && go == 0) {// Говорить
                           j["response"]["text"] = u8R"(Хорошо)";
                           for (int i = 0; i < j["response"]["buttons"].size(); i++)
                           {
                               if (j["response"]["buttons"][i]["title"] == u8R"(Говорить)")
                               {
                                   j["response"]["buttons"][i]["title"] = u8R"(Молчать)";
                               }
                           }
                           j["session_state"]["dtbv"] = true;
                       
                       }

                       else if (body["request"]["nlu"]["tokens"][0] == u8R"(корзина)") {// Говорить
                           j["response"]["text"] = u8R"(Корзина. Поможет организовать покупки.)";
                       
                       }
                       else if (body["request"]["nlu"]["tokens"][0] == u8R"(говорить)") {// Говорить
                           j["response"]["text"] = u8R"(Говорить. Включит голосового помощника.)";
                       
                       }
                       else if (body["request"]["nlu"]["tokens"][0] == u8R"(молчать)") {// Говорить
                           j["response"]["text"] = u8R"(Молчать. Отключит голосового помощника.)";
                       
                       }






                       else if (body["request"]["nlu"]["tokens"][0] == u8R"(помощь)")// Помощь
                       {
                           j["response"]["text"] = u8R"(Молчать. Выключит голосовую озвучкую. \n\n Говорить. Включит голосовую озвучку. \n\n Корзина. Поможет организовать покупки. \n\n Помощь. Выведет справку по командам. \n\n О чём рассказать подробнее?")";

                           for (int i = 0; i < j["response"]["buttons"].size(); i++)
                           {
                               if (j["response"]["buttons"][i]["title"] == u8R"(Помощь)")
                               {
                                   j["response"]["buttons"][i]["title"] = u8R"(Выход из режима справки)";
                               }
                           }

                           j["session_state"]["operating_mode"] = "help";

                       }
                       else if (exithelp == u8R"(выход из режима справки)") {// поправить поиск с 1 слова на всю фразу как будет ниже Ввести для кнопки и для комманды определитель
                           j["response"]["text"] = u8R"(Обращайся ещё)";
                           for (int i = 0; i < j["response"]["buttons"].size(); i++)
                           {
                               if (j["response"]["buttons"][i]["title"] == u8R"(Выход из режима справки)")
                               {
                                   j["response"]["buttons"][i]["title"] = u8R"(Помощь)";
                               }
                           }

                           j["session_state"]["operating_mode"] = "main";
                       }
                       // убрать возможность вызова команд внутри хелпа, мэин и хелп разные среды
                       else if (exithelp == u8R"(очистить корзину)") {// поправить поиск с 1 слова на всю фразу как будет ниже Ввести для кнопки и для комманды определитель
                           j["session_state"]["basket"].clear();
                           j["response"]["text"] = u8R"(Корзина пуста)";

                       }
                                              
                       else if (basketname == u8R"(добавить в корзину)") {// поправить поиск с 1 слова на всю фразу как будет ниже Ввести для кнопки и для комманды определитель // в режиме help ошибка
                           int szb = j["session_state"]["basket"].size();




                           j["session_state"]["basket"][szb]["price"] = price;
                           j["session_state"]["basket"][szb]["item"] = itemname;

                           j["response"]["text"] = u8R"(ОК)";

                       }
                                              
                       else if (basketname == u8R"(удалить из корзины)") {// поправить поиск с 1 слова на всю фразу как будет ниже Ввести для кнопки и для комманды определитель
                           int szb = j["session_state"]["basket"].size();
                           bool statusdel = false;
                           for (size_t i = 0; i < szb; i++)
                           {
                               if (j["session_state"]["basket"][i]["item"] == itemname)
                               {
                                   j["session_state"]["basket"].erase(i);
                                   j["response"]["text"] = u8R"(ОК)";
                                   statusdel = true;


                               }

                           }
                           if (!statusdel)
                           {
                               j["response"]["text"] = u8R"(Данного товара нет)";
                           }
                           

                       }
                                              
                       else if (exithelp == u8R"(что в корзине)") {// поправить поиск с 1 слова на всю фразу как будет ниже Ввести для кнопки и для комманды определитель

                           int szb = j["session_state"]["basket"].size();
                           string inbasket;
                           bool statusvac = true;
                           bool statuswhat = false;
                           for (int i = 0; i < szb; i++)
                           {
  
                               if (!empty(j["session_state"]["basket"][i]["item"]) && !empty(j["session_state"]["basket"][i]["price"])  ) {

                                   inbasket += string(j["session_state"]["basket"][i]["item"]).append("\t").append(string(j["session_state"]["basket"][i]["price"])).append(u8R"( ₽)").append("\n");
                                   statuswhat = true;
                               }

                               statusvac = false;
                           }

                           if (statuswhat)
                           {
                               j["response"]["text"] = inbasket;
                           }
                           else {

                               j["response"]["text"] = u8R"(Корзина пуста)";
                           }


                           //if (statusvac)
                           //{
                           //    j["response"]["text"] = u8R"(Корзина пуста)";
                           //}


                       }
                                                                     
                       else if (exithelp == u8R"(сумма)") {// поправить поиск с 1 слова на всю фразу как будет ниже Ввести для кнопки и для комманды определитель
                       int fullsum = 0;
                       int szb = j["session_state"]["basket"].size();
                       for (int i = 0; i < szb; i++)
                       {
                           if (!empty(j["session_state"]["basket"][i]["item"]) && !empty(j["session_state"]["basket"][i]["price"]))
                           {
                               string temp = j["session_state"]["basket"][i]["price"];
                              fullsum += stoi(temp);
                           }
                       }


                           j["response"]["text"] = to_string(fullsum).append(u8R"( ₽)");
                       }
                                                                     
                       else if (exithelp  == u8R"(покупка завершена)") {// поправить поиск с 1 слова на всю фразу как будет ниже Ввести для кнопки и для комманды определитель
                           j["response"]["text"] = u8R"(заходите еще)";
                       }



                       else {
                           j["response"]["text"] = u8R"(Неизвестная команда)";
                       
                       }

                       str = j.dump();
                   
                }

            }
        }


    // Отправляем ответ
    res.set_content(str, "text/json; charset=UTF-8");
}

int main() {
    Server svr;                            // Создаём сервер (пока-что не запущен)
    svr.Post("/", gen_response);           // Вызвать функцию gen_response на post запрос
    std::cout << "Start server... OK\n"; // cout использовать нельзя
    svr.listen("localhost", 3000);         // Запускаем сервер на localhost и порту 1234
}