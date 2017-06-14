class AddEventIdToActivities < ActiveRecord::Migration[5.1]
  def change
    add_column :activities, :event_id, :integer
  end
end
