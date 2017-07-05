class CreatePrereqs < ActiveRecord::Migration[5.1]
  def change
    create_table :prereqs do |t|
      t.integer :activity_id
      t.integer :prereq_id
    end
  end
end
