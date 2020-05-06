package com.example.ndkdemo.basic

import android.os.Bundle
import android.view.View
import androidx.appcompat.app.AppCompatActivity
import com.example.ndkdemo.R
import com.example.ndkdemo.bean.User

class DatatypeActivity : AppCompatActivity(), View.OnClickListener {
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_datatype)
        initData()
    }

    companion object {
        // Used to load the 'native-lib' library on application startup.
        init {
            System.loadLibrary("native-lib")
        }
    }

    private fun initData() {
        dataType(true,1,'r',2,5L,0.32,2.56f,8,"str", arrayOf("str1","str2","str3"),
            User(10021,"姓名","13200000000","ahud24254")
        )
    }

    external fun dataType(
        mBoolean:Boolean,
        mByte:Byte,
        mChar:Char,
        mShort: Short,
        mLong: Long,
        mDouble:Double,
        mFloat:Float,
        mInt:Int,
        mStr:String,
        mStrs:Array<String>,
        mUser:User
    )

    override fun onClick(p0: View?) {
        initData()
    }
}