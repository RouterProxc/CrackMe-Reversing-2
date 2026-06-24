# CrackMe-Reversing-2

Решаем CrackMe с популярного сайта.

Открываем файл в IDA и ловим функцию "start" 

<img width="290" height="272" alt="image" src="https://github.com/user-attachments/assets/36d19fc9-fe34-423e-8a66-823d5995517c" />

Видим что програма сначало вызывает функцию sub_1400026D0, а затем безусловно прыгает в sub_140002270
Для начала проверим что находится в sub_1400026D0.

<img width="975" height="887" alt="image" src="https://github.com/user-attachments/assets/7b1fca81-84e4-4232-905a-3c88ed548700" />
(data: __security_cookie dq 2B992DDFA232h)

В этой функции мы сначало получаем текущее время на ПК который открыл програму, потом считаем сколько тиков прошло.

Если кто то не знает, то при динамической отладке (пр. x64dbg) когда мы стоим на определенной инструкции тики процессора обрабатываются как и при обычном выполнении програмы без отладки. Тоесть если програма видит что прошло слишком много тиков при выполнении функции - значит идет отладка програмы. 
Выходит что sub_1400026D0 - функция антиотладки.

Теперь проверим что находится в sub_140002270.

<img width="396" height="775" alt="image" src="https://github.com/user-attachments/assets/1bd7720b-8d14-4440-8cac-1d1a5eb15f5e" />

Очень большая структура, изучем внимательнее.

<img width="554" height="575" alt="image" src="https://github.com/user-attachments/assets/9708af74-1af2-4646-bb5c-a553134d4237" />

Одна из двух функций после аргументов и перед выходом из програмы - наш OEP(main).
Проверяю первую и угадываю.

<img width="957" height="887" alt="image" src="https://github.com/user-attachments/assets/50b901f2-8aa4-4463-bc86-37511a43cedc" />

Дальше идет разветвление

<img width="957" height="72" alt="image" src="https://github.com/user-attachments/assets/9564984c-4fb1-46fe-9c9a-4a07f60e6ee2" />

Функция идущая перед разветвлением и test скорее всего проверяет пароль на валидность
