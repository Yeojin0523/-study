package ddwu.com.mobile.fooddbexam02

import android.util.Log
import android.view.LayoutInflater
import android.view.View
import android.view.ViewGroup
import androidx.recyclerview.widget.RecyclerView
import ddwu.com.mobile.fooddbexam02.data.FoodDto
import ddwu.com.mobile.fooddbexam02.databinding.ListItemBinding

class FoodAdapter (val foods : ArrayList<FoodDto>)
    : RecyclerView.Adapter<FoodAdapter.FoodViewHolder>() {
    val TAG = "FoodAdapter"

    /*재정의 필수 - 데이터의 개수 확인이 필요할 때 호출*/
    override fun getItemCount(): Int = foods.size

    /*재정의 필수 - 각 item view 의 view holder 생성 시 호출*/
    override fun onCreateViewHolder(parent: ViewGroup, viewType: Int): FoodViewHolder {
        val itemBinding = ListItemBinding.inflate(LayoutInflater.from(parent.context), parent, false)
        return FoodViewHolder(itemBinding)
    }

    /*재정의 필수 - 각 item view 의 항목에 데이터 결합 시 호출*/
    override fun onBindViewHolder(holder: FoodViewHolder, position: Int) {
        holder.itemBinding.tvText.text = foods[position].toString()
    }

    inner class FoodViewHolder(val itemBinding: ListItemBinding)
        : RecyclerView.ViewHolder(itemBinding.root) {
            init {
                /*RecyclerView 항목 클릭 시 외부 click 이벤트 리스너 호출*/
                itemBinding.root.setOnClickListener{
                    listener?.onItemClick(it, adapterPosition)  // RecyclerView 항목 클릭 시 외부에서 지정한 리스너 호출
                    Log.d(TAG, foods[adapterPosition].toString()) // 실행해야 할 부분은 여기에 두면 안돼. 여기서 수행해야 할 기능을 밖에서 만들어서 전
                } // 어댑터를 클릭했을 때, 실행해야 할 부분을 밖에서 정의하고 가져오자
                itemBinding.root.setOnClickListener{
                    Log.d(TAG, "LONG CLICK")
                    longClickListener?.onItemClick(it, adapterPosition)
                }
            }
        }
    interface onItemLongClickListener{
        fun onItemLongClick(view : View, position : Int) : Boolean
    }
    var longClickListener : OnItemClickListener? = null // longClick이 구현 안될수도 있잖아.

    fun setOnItemLongClickListener(listener: OnItemClickListener?){
        this.longClickListener = listener
    }

    /*사용자 정의 외부 click 이벤트 리스너 설정 */
    var listener : OnItemClickListener? = null  // listener 를 사용하지 않을 때도 있으므로 null

    interface OnItemClickListener {
        fun onItemClick(view : View, position : Int)
    }

    fun setOnItemClickListener(listener: OnItemClickListener?) {
        this.listener = listener
    }
}



