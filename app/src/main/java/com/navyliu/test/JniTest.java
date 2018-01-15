package com.navyliu.test;

/**
 * Created by Administrator on 2017-12-19.
 */

public class JniTest {
	/**
	 * 将用C++代码实现，在android代码中调用的方法：获取当前app的包名
	 * @param o
	 * @return
	 */
	public static native String getPackname(Object o);

	/**
	 * 加载so库或者jni库，在使用到该库之前加载就行，不一定非要卸载这个类内
	 * 系统自己会判断扩展名是dll还是so，这里加载lib JNI_ANDROID_TEST.so
	 */
	static {
		System.loadLibrary("JNI_ANDROID_TEST");
	}
}
