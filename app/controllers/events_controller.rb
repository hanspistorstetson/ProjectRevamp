class EventsController < ApplicationController
  before_action :find_event, only: [:show, :edit, :update, :destroy]
  before_action :authenticate_user!, only: [:new, :create, :update, :edit, :destroy]

  def index
    @events = Event.all.order("DATEOF")
  end


  def show

  end

  def join

    user_id = params[:event][:user_id]
    event_id = params[:event_id]
    event = Event.find(event_id)
    user = User.find(user_id)
    user.events << event
    flash[:success] = "You have successfully signed up for " + event.title
    redirect_to Event.find(event_id)

  end

  def leave

    user_id = params[:event][:user_id]
    event_id = params[:event_id]
    user = User.find(user_id)
    user.events.delete(Event.find(event_id))
    event = Event.find(event_id)
    flash[:alert] = "You have successfully unsubscribed from " + event.title
    redirect_to root_path
  end

  def new
    @event = Event.new
  end

  def create
    @event = Event.new event_params
    @event.dateof = Date.parse(params[:dateof])
    puts "#########"
    puts @event.host_id
    if @event.save
      flash[:success] = "You succesfully created an event"
      User.find(@event.host_id).events << @event
      redirect_to @event
    else
      flash[:danger] = "Your event did not save successfully"
      render 'new'
    end
  end


  def edit

  end

  def update
    if @event.update event_params
      flash[:success] = "Successfully updated your event"
      redirect_to @event
    else
      flash[:danger] = "Your event was not successfully updated "
      render 'edit'
    end
  end

  def destroy
    @event.users.each do |usr|
      usr.events.delete(@event)
    end
    @event.destroy
    redirect_to events_path

  end


  private

  def event_params
    params.require(:event).permit(:title, :description, :dateof, :host_id)
  end

  def find_event
    @event = Event.find(params[:id])
  end

end
