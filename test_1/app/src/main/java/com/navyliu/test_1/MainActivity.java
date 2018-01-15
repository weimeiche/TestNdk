package com.navyliu.test_1;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.TextView;

public class MainActivity extends AppCompatActivity {

	// Used to load the 'native-lib' library on application startup.
	static {
		System.loadLibrary("native-lib");
	}

	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.activity_main);

		// Example of a call to a native method
		TextView tv = (TextView) findViewById(R.id.sample_text);
		tv.setText(stringFromJNI());
		TextView tv1 = (TextView) findViewById(R.id.tv_app_package_name);
		tv1.setText("packageName: " + JniTest.getPackname(MainActivity.this));
		TextView helloTxt = (TextView)findViewById(R.id.txt_jni_hello);
		helloTxt.setText("hello=="+JNIDynamicUtils.getHelloStringFromJNI());
		TextView sumTxt = (TextView)findViewById(R.id.txt_jni_sum_two_int);
		sumTxt.setText(JNIDynamicSumUtils.getSumFromJNI(1,2));
	}

	public void thorwException(View view){
		// tvInfo为界面上的一个TextView控件
		TextView exceptionTxt = (TextView)this.findViewById(R.id.txt_throw_exception);
		EditText exceptionEdit = (EditText)this.findViewById(R.id.edit_throw_exception);
		TextView asdf = null;
		try {
			exceptionTxt.setText(exceptionEdit.getText().toString() + "\n" + "--->dynamic jni: " + JNIDynamicExceptionUtils.getStrLength(exceptionEdit.getText().toString()));
		} catch (NullPointerException e) {
			exceptionTxt.setText(asdf.getText().toString() + "\n" + "--->dynamic jni:" + e);
		} catch (IllegalArgumentException e) {
			exceptionTxt.setText(exceptionEdit.getText().toString() + "\n" + "--->dynamic jni:" + e);
		}
	}

	/**
	 * A native method that is implemented by the 'native-lib' native library,
	 * which is packaged with this application.
	 */
	public native String stringFromJNI();
}
