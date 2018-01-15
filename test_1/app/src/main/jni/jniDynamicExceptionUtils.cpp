//
// Created by Administrator on 2017-12-20.
//

#include <stdio.h>
#include <jni.h>
#include <stdlib.h>

// C++层 native函数
jint getLengthOfStr(JNIEnv *env, jclass clz, jstring str){
    if (str == NULL){
        // 抛出空指针异常
        jclass  clz = env->FindClass("java/lang/NullPointerException");
        jmethodID methodId = env->GetMethodID(clz, "<init>", "()V");
        jthrowable throwable = (jthrowable) env->NewObject(clz, methodId);
        env->Throw(throwable);
    }else{
        jint len = env->GetStringUTFLength(str);
        if (len == 5){
            // 抛出IllegalArgumentException异常
            env->ThrowNew(env->FindClass("java/lang/IllegalArgumentException"), "this is IllegalArgumentException error form C++, because the str length is 5");
        } else{
            return len;
        }
    }
}

/**
 * JNINativeMethod油三部分组成，可添加多组对应
 * （1）Java中的函数名；
 * （2）函数签名，格式为（输入参数类型）返回值类型
 *()Ljava/lang/String;()表示无参；Ljava/lange/String;表示返回String，在对象名（包括包名，“/”间隔）签名加上L，分号结尾
 * （3）native函数名
 */
static JNINativeMethod gMethods[] = {{
                                             "getStrLength", "(Ljava/lang/String;)I", (void *)getLengthOfStr
                                     }};

// System.loadLibrary过程中会自动挑用JNI_OnLoad,在此进行动态注册
JNIEXPORT jint JNICALL JNI_OnLoad(JavaVM *jvm, void *reserved){
    JNIEnv *env = NULL;
    jint result = JNI_FALSE;

    // 获取env指针
    if (jvm->GetEnv((void**) &env, JNI_VERSION_1_6) != JNI_OK){
        return result;
    }
    if (env == NULL){
        return result;
    }
    // 获取类引用，写类的全路径（包名+类名）。FindClass等JNI函数将在后面讲解
    jclass  clazz = env->FindClass("com/navyliu/test_1/JNIDynamicExceptionUtils");
    if (clazz == NULL){
        return result;
    }
    // 注册方法
    if (env->RegisterNatives(clazz, gMethods, sizeof(gMethods)/ sizeof(gMethods[0])) < 0){
        return result;
    }
    // 成功
    result = JNI_VERSION_1_6;
    return result;
}
