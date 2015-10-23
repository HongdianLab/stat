/* 
 * File:   MetricStore.h
 * Author: hang.gao@dian.fm
 *
 * Created on July 7, 2015, 11:01 AM
 */

#ifndef METRICSTORE_H
#define	METRICSTORE_H

#include <string>
#include <time.h>
#include <pthread.h>


#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"
#include <iostream>

using namespace hdrapidjson;

class MetricStore  
{
public:
    bool addStat(std::string jsonstr);
    std::string getAllData();

	MetricStore()
    {
        _store.SetArray();
    }

    ~MetricStore()
    {
        _store.Clear();
    }

private:
    Document _store;
};


// 检查数据类型
#define json_check_is_bool(value, strKey) (value.HasMember(strKey) && value[strKey].IsBool())
#define json_check_is_string(value, strKey) (value.HasMember(strKey) && value[strKey].IsString())
#define json_check_is_int32(value, strKey) (value.HasMember(strKey) && value[strKey].IsInt())
#define json_check_is_uint32(value, strKey) (value.HasMember(strKey) && value[strKey].IsUint())
#define json_check_is_int64(value, strKey) (value.HasMember(strKey) && value[strKey].IsInt64())
#define json_check_is_uint64(value, strKey) (value.HasMember(strKey) && value[strKey].IsUint64())
#define json_check_is_float(value, strKey) (value.HasMember(strKey) && value[strKey].IsFloat())
#define json_check_is_double(value, strKey) (value.HasMember(strKey) && value[strKey].IsDouble())

#define json_check_is_number(value, strKey) (value.HasMember(strKey) && value[strKey].IsNumber())
#define json_check_is_array(value, strKey) (value.HasMember(strKey) && value[strKey].IsArray())

// 得到对应类型的数据，如果数据不存在则得到一个默认值
#define json_check_bool(value, strKey) (json_check_is_bool(value, strKey) && value[strKey].GetBool())
#define json_check_string(value, strKey) (json_check_is_string(value, strKey) ? value[strKey].GetString() : "")
#define json_check_int32(value, strKey) (json_check_is_int32(value, strKey) ? value[strKey].GetInt() : 0)
#define json_check_uint32(value, strKey) (json_check_is_uint32(value, strKey) ? value[strKey].GetUint() : 0)
#define json_check_int64(value, strKey) (json_check_is_int64(value, strKey) ? ((value)[strKey]).GetInt64() : 0)
#define json_check_uint64(value, strKey) (json_check_is_uint64(value, strKey) ? ((value)[strKey]).GetUint64() : 0)
#define json_check_float(value, strKey) (json_check_is_float(value, strKey) ? ((value)[strKey]).GetFloat() : 0)
#define json_check_double(value, strKey) (json_check_is_double(value, strKey) ? ((value)[strKey]).GetDouble() : 0)

#endif	/* METRICSTORE_H */
