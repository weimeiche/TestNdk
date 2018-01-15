LOCAL_PATH := $(call my-dir)
#  // 设置当前的编译目录（Android.mk所在的目录）

include $(CLEAR_VARS)
# // 清除LOCAL_XX变量（LOCAL_PATH除外）
LOCAL_MODULE := JNI_ANDROID_TEST
#// 指定当前编译模块的名称
LOCAL_SRC_FILES := jniTest.cpp
# // 编译模块需要的源文件
include $(BUILD_SHARED_LIBRARY)
# // 指定编译出的库类型，BUILD_SHARED_LIBRARY：动态库；BUILD_STATIC_LIBRARY：静态库， BUILD_EXECUTEABLE指：可执行文件



include $(CLEAR_VARS)
LOCAL_MODULE := JNI_DYNAMIC_ANDROID_TEST
LOCAL_SRC_FILES := jnidynamicutils.cpp
include $(BUILD_SHARED_LIBRARY)


include $(CLEAR_VARS)
LOCAL_MODULE := JNI_DYNAMIC_SUM_ANDROID_TEST
LOCAL_SRC_FILES := jnidynamicsumutils.cpp
include $(BUILD_SHARED_LIBRARY)


include $(CLEAR_VARS)
LOCAL_MODULE := JNI_DYNAMIC_EXCEPTION_ANDROID_TEST
LOCAL_SRC_FILES := jniDynamicExceptionUtils.cpp
include $(BUILD_SHARED_LIBRARY)

include $(CLEAR_VARS)
LOCAL_MODULE := JNI_DYNAMIC_PICTURE_GRAY_ANDROID_TEST
LOCAL_SRC_FILES := jniDynamicPictureGrayUtils.cpp
include $(BUILD_SHARED_LIBRARY)