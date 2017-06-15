class AddColumnToSignup < ActiveRecord::Migration[5.1]
  def change
    add_column :signups, :user_id, :integer
    add_column :signups, :event_id, :integer
  end
end
