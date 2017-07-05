class AddFinishedToActivityUsers < ActiveRecord::Migration[5.1]
  def change
    add_column :checkins, :finished, :boolean, default: false
  end
end
