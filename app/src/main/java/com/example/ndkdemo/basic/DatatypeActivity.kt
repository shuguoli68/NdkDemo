package com.example.ndkdemo.basic

import android.os.Bundle
import androidx.appcompat.app.AppCompatActivity
import com.example.ndkdemo.R
import com.example.ndkdemo.bean.User

class DatatypeActivity : AppCompatActivity() {
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_datatype)
        initData()
    }

    private fun initData() {

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
}