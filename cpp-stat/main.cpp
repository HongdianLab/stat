#include "MetricStore.h"

int main() {
    std::string data="{\
            \"uuid\": \"ab6d5f06-23e5-11e5-8867-56847afe9799\",\"metric\": \"media.blocktime\",\
            \"timestamp\": 1436190435,\
            \"value\": 0.51,\
            \"tags\": {\
                \"user_id\": \"1\",\
                \"room_id\": \"2\",\
                \"app\": \"hongdian\",\
                \"live_id\": \"72843763\"\
            }\
        }";
    MetricStore *s = new MetricStore();
    s->addStat(data);
    std::cout << s->getAllData() << std::endl;
    return 0;
}
