class CreateActivityUsers < ActiveRecord::Migration[5.1]
  def change
    create_table :checkins do |t|
      t.integer :activity_id
      t.integer :user_id
      t.timestamps
    end
  end
end
