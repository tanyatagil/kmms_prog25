CPP_FILES="main.cpp menu_functions.cpp menu_items.cpp"
APP=example

if [ -f $APP ]; then rm $APP
fi

g++ $CPP_FILES -o $APP

./$APP
