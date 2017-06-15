class AddFinishedToActivityUsers < ActiveRecord::Migration[5.1]
  def change
    add_column :checkin, :finished, :boolean, default: false
  end
end
