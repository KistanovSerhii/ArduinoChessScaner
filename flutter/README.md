# Smart chess board

## Getting Started

Для запуска приложения выполните:

    flutter pub get
    flutter pub get update
    flutter packages pub run build_runner build
    flutter run

# Для VS Code необходимо указать путь к dart sdk, flutter sdk, android sdk

    dart sdk и flutter sdk указал в настройках VS code
    android sdk указал через терминал vs code командой: flutter config --android-sdk path
    
    
    dart sdk и flutter sdk - скачал с https://dart.dev/get-dart
    android sdk - установил android studio

# ВАЖНО:
    Откройте проект повторно после указания sdk, переменные среды и т.д.

Добавить разрешения bluetooth для android и ios:
    см. плагин "flutter_blue"

После установки минимальной версии в android gradle необходимо - заменить класс gradle (там где будет ругаться):
The latest Android SDK does not support GradleException(), instead use FileNotFoundException()

, а также необходимо в android studio запустить менеджер sdk и установить "Android SDK Command-line Tools (latest)"
затем перейти в проект и выполнить в терминал команду "flutter doctor --android-licenses"

Для инициализации плагина bluetooth (flutter pub get update) необходимо выполнить инструкцию:
https://kb.msp360.com/standalone-backup/general/a-required-privilege-is-not-held-by-client