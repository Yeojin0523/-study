package ddwu.com.mobile.exam01

import android.content.Intent
import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import ddwu.com.mobile.exam01.databinding.ActivityMainBinding

class MainActivity : AppCompatActivity() {

    val binding by lazy {
        ActivityMainBinding.inflate(layoutInflater)
    }

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(binding.root)

        binding.btnSend.setOnClickListener {
            val intent = Intent(this, SubActivity::class.java)
            val editTextValue = binding.etReceivedMsg.text.toString() // EditText의 값을 가져오기
            intent.putExtra("rslt", editTextValue) // 값을 Intent에 추가
            startActivity(intent) // SubActivity를 시작
        }
    }
}
