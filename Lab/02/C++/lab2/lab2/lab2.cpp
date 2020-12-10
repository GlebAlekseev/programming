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

    ifstream lstrc("config.json");
    json config;
    lstrc >> config;
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





                        /*   cout << config["webhooks"][0];*/
                           //string urls = config["webhook"][0];
                           string url;
                           for (int i = 0; i < config["webhooks"].size(); i++)// отправка вебхуков на подписанный сервисы со страницы /webhooks
                           {
                               //После http:// https:// и до /  heder после [/  footer
                               url = config["webhooks"][i];
                               //cout << url << endl;
                               //cout << i << endl;
                               //url.substr(0);


                               string vihod = u8R"({"user_id": "1","check" : []})";
                               json temp = json::parse(vihod);


                               if (!empty(body["session"]["user"]["user_id"]))
                               {
                                   temp["user_id"] = body["session"]["user"]["user_id"];
                               }
                               else {
                                   temp["user_id"] = "anonymous";
                               }
                               





                               int szb = j["session_state"]["basket"].size();
                               bool statuswhat = false;
                               for (int k = 0; k < szb; k++)
                               {

                                   if (!empty(j["session_state"]["basket"][i]["item"]) && !empty(j["session_state"]["basket"][i]["price"])) {

                                       temp["check"].push_back(j["session_state"]["basket"][k]);
                                       statuswhat = true;
                                   }
                               }
                               if (statuswhat)
                               {
                                   //cout << url.find("ttp") << " " << url << endl;
                                   if (url.find("ttp"))
                                   {/*url.substr(0, url.find("/", 9))*/
                                       /*url.substr(url.find("/", 9))*/
                                       string header = url.substr(0, url.find("/", 9));
                                       string footer = url.substr(url.find("/", 9));
                                       Client cli(header.c_str());
                                       auto resd = cli.Post(footer.c_str(), temp.dump(), "application/json");

                                       if (resd) {
                                           // Проверяем статус ответа, т.к. может быть 404 и другие
                                           if (resd->status == 200) {
                                               // В res->body лежит string с ответом сервера
                                               std::cout << resd->body << std::endl;
                                           }
                                           else {
                                               std::cout << "Status code: " << resd->status << std::endl;
                                           }
                                       }
                                       else {
                                           auto err = resd.error();
                                           std::cout << "Error code: " << err << std::endl;
                                       }




                                   }

                                   //if (url.find("http://"))
                                   //{
                                   //    cout << "localhost5000";
                                   //    string header = url.substr(0, url.find("/", 9));
                                   //    cout << header;
                                   //    string footer = url.substr(url.find("/", 9));
                                   //    cout << footer;
                                   //    Client cli(header.c_str());
                                   //    auto res = cli.Post(footer.c_str(), temp.dump(), "text/json");
                                   //}


                               }




                           }

                          /* j["response"]["end_session"] = true;*/
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



// В этой функции формируем ответ сервера на запрос
void gen_responseHook(const Request& req, Response& res) {
    ifstream lsrc("config.json");
    json config;
    lsrc >> config;

    //cout << config["webhooks"];

    if (req.method == "POST") {

        if (req.has_param("del"))
        {
            auto val_del = req.get_param_value("del");

            for (int i = 0; i < config["webhooks"].size(); i++)
            {
                cout << json(val_del) << endl;
                cout << " i = " << i << " " << config["webhooks"][i] << endl;
                if (config["webhooks"][i] == val_del)
                {
                    config["webhooks"].erase(i);
                    ofstream csrc("config.json");
                    csrc << config;
                }
            }

            //config["webhooks"].push_back(val_set);
        }
        //       
        if (req.has_param("set"))
        {
            auto val_set = req.get_param_value("set");
            /*cout << val_set;*/

            config["webhooks"].push_back(val_set);
            ofstream csrc("config.json");
            csrc << config;
        }


    }

    cout << config << endl;
    //cout << config["webhooks"].size();

    ifstream file("Webhooks.html"); // Файловая переменная
    string str;                 // Буфер. Тут будет текст файла
    getline(file, str, '\0');// str html страница изменить значения temp*2

    string word1 = "{webhooks_list}";
    int num1 = size(word1);

    string stro;
    for (int i = 0; i < config["webhooks"].size(); i++)
    {
        stro.append(u8"<div class=\"form - row align - items - center\"><div class = \"col\" ><input type = \"text\" value = \" ").append(config["webhooks"][i]).append(u8" \" class = \"form-control mb-2\" disabled></div><div class = \"col\"><button type = \"submit\" name = \"del\" value = \"").append(config["webhooks"][i]).append(u8"\" class = \"btn btn-danger mb-2\">Удалить</button></div></div>");

        //string() + string(config["webhooks"][i]) + string(" \" class = \"form-control mb-2\" disabled></div><div class = \"col\"><button type = \"submit\" name = \"del\" value = \"{Webhook URL}\" class = \"btn btn-danger mb-2\">Удалить</button></div></div>");

        for (int i = 0; i < stro.length(); i++)
        {
            if (stro[i] == '\\')
            {
                stro.erase(i);
            }
        }
    }

    //cout << "htnl" << stro;
    str.replace(str.find(word1), num1, stro);


    // Отправляем ответ
    res.set_content(str, "text/html; charset=UTF-8");// Вывод

}


int main() {
    Server svr;                            // Создаём сервер (пока-что не запущен)
    svr.Post("/", gen_response);           // Вызвать функцию gen_response на post запрос
    svr.Post("/webhooks", gen_responseHook);           // Вызвать функцию gen_response на post запрос
    svr.Get("/webhooks", gen_responseHook);
    std::cout << "Start server... OK\n"; // cout использовать нельзя




    //newconfig.parse("{\"webhooks\": []}");
    //cout << strnewconfig;
    ifstream src("config.json");
    if (!src)
    {
        //    json newconfig;
        string strnewconfig = "{\"webhooks\": []}";

        /* delbckspl(strnewconfig);*/
         // {"webhooks":["vk.com","yandex.ru","jsoneditoronline.org"]}

        json newconfig = json::parse(strnewconfig);


        ofstream csrc("config.json");
        csrc << newconfig;

    }
    ifstream lsrc("config.json");
    json config;
    lsrc >> config;

   /* cout << "first" << config << endl;*/




    svr.listen("localhost", 3000);         // Запускаем сервер на localhost и порту 1234
}