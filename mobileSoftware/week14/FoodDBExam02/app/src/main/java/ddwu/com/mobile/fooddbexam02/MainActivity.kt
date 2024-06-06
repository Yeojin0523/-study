package ddwu.com.mobile.fooddbexam02

import android.annotation.SuppressLint
import android.content.Intent
import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import android.provider.BaseColumns
import android.view.View
import android.widget.Toast
import androidx.recyclerview.widget.LinearLayoutManager
import ddwu.com.mobile.fooddbexam02.data.FoodDBHelper
import ddwu.com.mobile.fooddbexam02.data.FoodDto
import ddwu.com.mobile.fooddbexam02.databinding.ActivityMainBinding

class MainActivity : AppCompatActivity() {

    val TAG = "MainActivity"
    val REQ_ADD = 100
    val REQ_UPDATE = 200

    val binding by lazy {
        ActivityMainBinding.inflate(layoutInflater)
    }
    lateinit var foods : ArrayList<FoodDto>

    /*
    val foodDao by lazy{
        FoodDao()
    }*/

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(binding.root)

        /*RecyclerView 의 layoutManager 지정*/
        binding.rvFoods.layoutManager = LinearLayoutManager(this).apply {
            orientation = LinearLayoutManager.VERTICAL
        }

        foods = getAllFoods()               // DB 에서 모든 food를 가져옴
        val adapter = FoodAdapter(foods)        // adapter 에 데이터 설정
        binding.rvFoods.adapter = adapter   // RecylcerView 에 adapter 설정

        binding.btnAdd.setOnClickListener(){
            // 추가 액티비티 호출
            val intent = Intent(this@MainActivity, AddActivity::class.java)
            startActivityForResult(intent, REQ_ADD) // FOR RESULT로 호출하고 있음 -> 응답을 받겠다는 의지
        }
        adapter.setOnItemClickListener(object : FoodAdapter.OnItemClickListener{
            override fun onItemClick(view: android.view.View, position: kotlin.Int) {
                // 현재 항목 DB 삭제 -> id 가지고 삭제하는 것!
                val result = deleteFood(foods[position])

                // 화면 갱신
                if (result > 0) {
                    foods.clear()
                    foods.addAll(getAllFoods())
                    binding.rvFoods.adapter?.notifyDataSetChanged()
                }
                return true
            }
        })

        adapter.setOnItemClickListener(object : FoodAdapter.OnItemClickListener {
            override fun onItemClick(view: View, position: Int) {
                val intent = Intent(this@MainActivity, UpdateActivity::class.java)
                intent.putExtra("dto", foods.get(position) )   // 클릭한 RecyclerView 항목 위치의 dto 전달startActivityForResult(intent, REQ_UPDATE)      // 수정결과를 받아오도록 Activity 호출
                startActivityForResult(intent, REQ_UPDATE) // FOR RESULT로 호출하고 있음 -> 응답을 받겠다는 의지
            } // 람다 형식으로 만들어보기!!
        })
    }

    override fun onResume() {
        super.onResume()
//        adapter.notifyDataSetChanged()   // 액티비티가 보일 때마다 RecyclerView 를 갱신하고자 할 경우
    }
    // resume에 넣으면, 항상 갱신

    override fun onActivityResult(requestCode: Int, resultCode: Int, data: Intent?) { // 여기서 응답
        super.onActivityResult(requestCode, resultCode, data)
        when (requestCode) {
            REQ_UPDATE -> {
                if (resultCode == RESULT_OK) { // ok면 dv 부터 다시 읽어와서 보여줘야 해
                    foods.clear()                       // 기존 항목 제거
                    foods.addAll(getAllFoods())         // 항목 추가
                    binding.rvFoods.adapter?.notifyDataSetChanged()      // RecyclerView 갱신
                } else {
                   Toast.makeText(this@MainActivity, "취소됨", Toast.LENGTH_SHORT).show()
               }
            }
            REQ_ADD -> {
                if (resultCode == RESULT_OK) { // ok면 dv 부터 다시 읽어와서 보여줘야 해
                    foods.addAll(getAllFoods())         // 항목 추가
                    binding.rvFoods.adapter?.notifyDataSetChanged()      // RecyclerView 갱신
                } else {
                    Toast.makeText(this@MainActivity, "취소됨", Toast.LENGTH_SHORT).show()
                }
            }
        }
    }
}
