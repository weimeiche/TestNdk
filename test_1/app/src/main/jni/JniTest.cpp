//
// Created by Administrator on 2017-12-19.
//
#include <stdlib.h>
#include <stdio.h>
#include <jni.h>
#include "JniTest.h"

JNIEXPORT jstring JNICALL
Java_com_navyliu_test_11_JniTest_getPackname(JNIEnv *env, jclass clazz, jobject obj) {
    jclass native_class = env->GetObjectClass(obj);
    jmethodID mId = env->GetMethodID(native_class, "getPackageName", "()Ljava/lang/String;");
    jstring packName = static_cast<jstring>(env->CallObjectMethod(obj, mId));
    return packName;
}