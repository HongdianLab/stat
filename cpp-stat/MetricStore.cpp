/* 
 * File:   MetricStore.cpp
 * Author: hang.gao@dian.fm
 * 
 * Created on July 7, 2015, 11:01 AM
 */

#include "MetricStore.h"
#include <sstream>
#include <utility>


const static int MAX_STAT_SIZE = 1024;

bool _checkValue(Document value){
    bool ret = true;
    return ret;
}

bool MetricStore::addStat(std::string jsonstr)
{
    bool ret = true;

    Document value(kObjectType, &_allocator);
    value.Parse(jsonstr.c_str());
    ret = _checkValue(value);
    if (ret) {
        _store.PushBack(value, _allocator);
    }

    return ret;
}

std::string MetricStore::getAllData() {
    int timestamp = (int)time(NULL);
    Document value(kObjectType, &_allocator);

    if _store
    Document store;
    store.CopyFrom(_store, store.GetAllocator());

    value.AddMember("timestamp_send",   timestamp,  _allocator);
    value.AddMember("data",             store,     _allocator);

    StringBuffer sb;
    //PrettyWriter<StringBuffer> writer(sb);
    Writer<StringBuffer> writer(sb);
    value.Accept(writer);

    _store.Clear();
    return sb.GetString();
}
 
/****************************************************************************
{
    "timestamp_send": 1436257597,//log上传时的本地时间
    "data": [
        {
            "uuid": "986d5f06-23e5-11e5-8867-56847afe9799",//必需,防止重复上传, 使用uuidv1 (时间+mac地址+sequenceID)
            "metric": "media.blocktime", //必需，字符串，指标名称
            "timestamp": 1436190432, //整型，时间戳,单位秒,数据点采集时间
            "value": 1.11,/必需，整型、浮点型，指标值
            "tags": {
                "user_id": "1",
                "room_id": "2",
                "app": "hongdian",
                "live_id": "72843763"
            }//必需，hash对象，kv对
        },
        {
            "uuid": "ab6d5f06-23e5-11e5-8867-56847afe9799",
            "metric": "media.blocktime",
            "timestamp": 1436190435,
            "value": 0.51,
            "tags": {
                "user_id": "1",
                "room_id": "2",
                "app": "hongdian",
                "live_id": "72843763"
            }
        },
        {
            "uuid": "de6d5f06-23e5-11e5-8867-56847afe9799",
            "metric": "media.blocktime",
            "timestamp": 1436190440,
            "value": 2.11,
            "tags": {
                "user_id": "1",
                "room_id": "2",
                "app": "hongdian",
                "live_id": "72843763"
            }
        }
    ]
}
*****************************************************************************/
