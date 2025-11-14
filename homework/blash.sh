CPP_FILES="io.cpp sorting.cpp main.cpp"
APP=example

if [ -f $APP ]; then rm $APP
fi

g++ $CPP_FILES -o $APP

./$APP
