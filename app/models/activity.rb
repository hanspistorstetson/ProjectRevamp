class Activity < ApplicationRecord
  belongs_to :event
  has_many :checkins
  has_many :users, :through => :checkins
  has_many :prereqs
  has_many :activities, :through => :prereqs


end
