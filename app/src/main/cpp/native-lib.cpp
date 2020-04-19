#include <jni.h>
#include <string>

// __VA_ARGS__ 代表 ...的可变参数
#define LOGD(...) __android_log_print(ANDROID_LOG_DEBUG, TAG,  __VA_ARGS__);
#define LOGE(...) __android_log_print(ANDROID_LOG_ERROR, TAG,  __VA_ARGS__);
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO, TAG,  __VA_ARGS__);


extern "C" JNIEXPORT jstring JNICALL
Java_com_example_ndkdemo_MainActivity_stringFromJNI(
        JNIEnv* env,
        jobject /* this */) {
    std::string hello = "Hello from C++";
    return env->NewStringUTF(hello.c_str());
}
extern "C"
JNIEXPORT void JNICALL
Java_com_example_ndkdemo_basic_DatatypeActivity_dataType(JNIEnv *env, jobject thiz,
                                                         jboolean m_boolean, jbyte m_byte,
                                                         jchar m_char, jshort m_short, jlong m_long,
                                                         jdouble m_double, jfloat m_float,
                                                         jint m_int, jstring m_str,
                                                         jobjectArray m_strs, jobject m_user) {
    unsigned char boolean1 = m_boolean;
    LOGD("boolean类型值- %d",boolean1);

    char byte1 = m_byte;
    LOGD("byte类型值- %d",byte1);

    char char1 = m_char;
    LOGD("char类型值- %s",char1);

    short short1 = m_short;
    LOGD("short类型值- %d",short1);

    long long1 = m_long;
    LOGD("long类型值- %d",long1);

    double double1 = m_double;
    LOGD("double类型值- %f",double1);

    float float1 = m_float;
    LOGD("float类型值- %f",float1);

    int int1 = m_int;
    LOGD("int类型值- %d",int1);

    const char *str = env->GetStringUTFChars(m_str, 0);
    LOGD("string类型值- %s", str);

    LOGD("数组类型","开始打印");
    jsize strsLen = env->GetArrayLength(m_strs);
    for (int i = 0; i < strsLen; ++i) {
        jobject jobject1 = env->GetObjectArrayElement(m_strs, i);
        jstring jstring1 = const_cast<jstring>(jobject1);
        const char *strItem = env->GetStringUTFChars(jstring1, NULL);
        LOGD("数组类型值 %d- %s", i, strItem);
        env->ReleaseStringUTFChars(jstring1, strItem);
    }
}