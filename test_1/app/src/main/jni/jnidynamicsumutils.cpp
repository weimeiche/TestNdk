//
// Created by Administrator on 2017-12-20.
//

#include <stdio.h>
#include <jni.h>
#include <stdlib.h>

// C++层 native函数
jstring sumOfTwoIntParameter(JNIEnv *env, jclass clz, jint i1, jint i2){
    char result[50];
    sprintf(result, "this is string from jni sum(%d,%d),result is %d", i1, i2, (i1+i2));
    return env->NewStringUTF(result);
}

/**
 * JNINativeMethod油三部分组成，可添加多组对应
 * （1）Java中的函数名；
 * （2）函数签名，格式为（输入参数类型）返回值类型
 *()Ljava/lang/String;()表示无参；Ljava/lange/String;表示返回String，在对象名（包括包名，“/”间隔）签名加上L，分号结尾
 * （3）native函数名
 */
static JNINativeMethod gMethods[] = {{
                                             "getSumFromJNI", "(II)Ljava/lang/String;", (void *)sumOfTwoIntParameter
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
    jclass  clazz = env->FindClass("com/navyliu/test_1/JNIDynamicSumUtils");
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
